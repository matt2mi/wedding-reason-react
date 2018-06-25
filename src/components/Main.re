let component = ReasonReact.statelessComponent("Main");
let make = _children => {
  ...component,
  render: _self => {
    let title = {js|Mariage Clé et Gus|js};

    <h1> (ReasonReact.string(title)) </h1>;
  },
};