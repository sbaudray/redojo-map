open ReactDOMRe;

open SimpleMap;

open Array;

let geographyStyle =
  Geography.styleT(
    ~default=
      Style.make(
        ~fill="#ECEFF1",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~hover=
      Style.make(
        ~fill="#607D8B",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~pressed=
      Style.make(
        ~fill="#FF5722",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
  );

let markerStyle =
  Marker.styleT(
    ~default=Style.make(~fill="#FF5722", ()),
    ~hover=Style.make(~fill="#FFFFFF", ()),
    ~pressed=Style.make(~fill="#FF5722", ()),
  );

let component = ReasonReact.statelessComponent("Map");

let make = (~markers, _children) => {
  ...component,
  render: _self =>
    <ComposableMap
      projectionConfig=(
        ComposableMap.projectionConfigT(
          ~scale=205,
          ~rotation=[|(-11), 0, 0|],
        )
      )
      width=980
      height=551>
      <ZoomableGroup>
        <Geographies geography="/world-50m.json">
          (
            (geographies, projection) =>
              geographies
              |> mapi((index, geography) =>
                   <Geography
                     key=(string_of_int(index))
                     geography
                     projection
                     style=geographyStyle
                   />
                 )
          )
        </Geographies>
        <Markers>
          (
            markers
            |> mapi((index, marker) =>
                 <Marker
                   key=(string_of_int(index))
                   marker
                   style=markerStyle>
                   <circle cx="0" cy="0" r="10" />
                 </Marker>
               )
          )
        </Markers>
      </ZoomableGroup>
    </ComposableMap>,
};
