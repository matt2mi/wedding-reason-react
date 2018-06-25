[%bs.raw {|require('./App.css')|}];

type route =
  | Main
  | Infos
  | Presence;

type state = {
  repoData: option(array(RepoData.repo)),
  route,
};

type action =
  | Loaded(array(RepoData.repo))
  | ChangeRoute(route);

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | ["main"] => Main
  | ["infos"] => Infos
  | ["presence"] => Presence
  | _ => Main
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {repoData: None, route: Main},
  didMount: ({send}) =>
    RepoData.fetchRepos()
    |> Js.Promise.then_(repoData => {
         send(Loaded(repoData));
         Js.Promise.resolve();
       })
    |> ignore,
  reducer: (action, state) =>
    switch (action) {
    | Loaded(loadedRepo) =>
      ReasonReact.Update({repoData: Some(loadedRepo), route: state.route})
    | ChangeRoute(route) =>
      ReasonReact.Update({repoData: state.repoData, route})
    },
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url =>
          self.send(ChangeRoute(url |> mapUrlToRoute))
        ),
      ReasonReact.Router.unwatchUrl,
    ),
  ],
  render: ({state}) =>
    <div className="App">
      <Header />
      <div>
        (
          switch (state.route) {
          | Main => <Main />
          | Infos => <Infos />
          | Presence => <Presence />
          }
        )
      </div>
    </div>,
};