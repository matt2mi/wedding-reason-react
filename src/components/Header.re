let component = ReasonReact.statelessComponent("Header");

let handleClick = (href, event) =>
  if (! ReactEventRe.Mouse.defaultPrevented(event)) {
    Js.log(href);
    ReactEventRe.Mouse.preventDefault(event);
    ReasonReact.Router.push(href);
  };

let make = _children => {
  ...component,
  render: _self => {
    let mainHref = "main";
    let infosHref = "infos";
    let presenceHref = "presence";

    <nav className="navbar navbar-expand-lg navbar-light bg-light">
      <a
        className="navbar-brand"
        href=mainHref
        onClick=(handleClick(mainHref))>
        (ReasonReact.string({js|Mariage Clé et Gus|js}))
      </a>
      <div className="collapse navbar-collapse" id="navbarSupportedContent">
        <ul className="navbar-nav mr-auto">
          <li className="nav-item active">
            <a
              className="nav-link"
              href=infosHref
              onClick=(handleClick(infosHref))>
              (ReasonReact.string("Infos pratiques"))
            </a>
          </li>
          <li className="nav-item active">
            <a
              className="nav-link"
              href=presenceHref
              onClick=(handleClick(presenceHref))>
              (ReasonReact.string({js|Présence|js}))
            </a>
          </li>
        </ul>
      </div>
    </nav>;
  },
};