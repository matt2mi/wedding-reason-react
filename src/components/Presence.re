let component = ReasonReact.statelessComponent("Presence");
let make = _children => {
  ...component,
  render: _self => <h1> (ReasonReact.string({js|Présence|js})) </h1>,
};