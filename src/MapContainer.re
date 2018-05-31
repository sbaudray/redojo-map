open SimpleMap;

open Array;

type state = array(Marker.markerT);

type action =
  | UpdateMarkers(array(Marker.markerT));

let component = ReasonReact.reducerComponent("MapContainer");

let make = (~username, _children) => {
  ...component,
  initialState: () => [||],
  didMount: self => {
    Fetcher.fetchPost(
      ~url="https://immense-river-25513.herokuapp.com/add-location",
      ~body=username,
    );
    Fetcher.fetchGet(
      ~url="https://immense-river-25513.herokuapp.com/locations", ~cb=response =>
      response
      |> map(location => {
           let (lat, lng) = Fetcher.location(location);
           Marker.markerT(
             ~coordinates=(lng, lat),
             ~name=Fetcher.username(location),
             ~markerOffset=0,
           );
         })
      |. UpdateMarkers
      |. self.send
    );
  },
  reducer: (action, _state) =>
    switch (action) {
    | UpdateMarkers(markers) => ReasonReact.Update(markers)
    },
  render: ({state}) => <Map markers=state />,
};
