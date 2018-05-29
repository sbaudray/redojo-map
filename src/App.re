open SimpleMap;

let component = ReasonReact.statelessComponent("App");

let geographyStyle =
  Geography.styleT(
    ~default=
      ReactDOMRe.Style.make(
        ~fill="#ECEFF1",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~hover=
      ReactDOMRe.Style.make(
        ~fill="#607D8B",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
    ~pressed=
      ReactDOMRe.Style.make(
        ~fill="#FF5722",
        ~stroke="#607D8B",
        ~strokeWidth="0.75",
        ~outline="none",
        (),
      ),
  );

let make = _children => {
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
      <Geographies geography="world-50m.json">
        (
          (geographies, projection) =>
            geographies
            |> Array.mapi((index, geography) =>
                 <Geography
                   key=(string_of_int(index))
                   geography
                   projection
                   style=geographyStyle
                 />
               )
        )
      </Geographies>
    </ComposableMap>,
};
