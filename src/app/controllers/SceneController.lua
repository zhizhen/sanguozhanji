
local SceneController = class("SceneController")

function SceneController:ctor(app)
	self.app_ = app
end

function SceneController:enterScene( SceneName )
	self.app_:enterScene(SceneName)
end

return SceneController