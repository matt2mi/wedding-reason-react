let component = ReasonReact.statelessComponent("Infos");
let make = _children => {
  ...component,
  render: _self => <h1> (ReasonReact.string("Information Pratiques")) </h1>,
};