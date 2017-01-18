local SceneController = require "app.controllers.SceneController"

local MyApp = class("MyApp", cc.load("mvc").AppBase)


function MyApp:onCreate()
    math.randomseed(os.time())
    self.sceneController = SceneController:create(self)
end

function MyApp:run( ... )
	-- body
	self.sceneController:enterScene("PlayScene")
end

return MyApp
