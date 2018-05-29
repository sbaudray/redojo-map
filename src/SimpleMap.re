module ComposableMap = {
  [@bs.deriving abstract]
  type projectionConfigT = {
    scale: int,
    rotation: array(int),
  };
  [@bs.deriving abstract]
  type jsProps = {
    projectionConfig: projectionConfigT,
    width: int,
    height: int,
  };
  [@bs.module "react-simple-maps"]
  external component : ReasonReact.reactClass = "ComposableMap";
  let make = (~projectionConfig, ~width, ~height, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=component,
      ~props=jsProps(~projectionConfig, ~width, ~height),
      children,
    );
};

module Geographies = {
  [@bs.deriving abstract]
  type jsProps = {geography: string};
  [@bs.module "react-simple-maps"]
  external component : ReasonReact.reactClass = "Geographies";
  let make = (~geography, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=component,
      ~props=jsProps(~geography),
      children,
    );
};

module Geography = {
  [@bs.abstract]
  type geographyT;
  [@bs.abstract]
  type projectionT;
  [@bs.deriving abstract]
  type styleT = {
    default: ReactDOMRe.Style.t,
    hover: ReactDOMRe.Style.t,
    pressed: ReactDOMRe.Style.t,
  };
  [@bs.deriving abstract]
  type jsProps = {
    geography: geographyT,
    projection: projectionT,
    style: styleT,
  };
  [@bs.module "react-simple-maps"]
  external component : ReasonReact.reactClass = "Geography";
  let make = (~geography, ~projection, ~style, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=component,
      ~props=jsProps(~geography, ~projection, ~style),
      children,
    );
};
