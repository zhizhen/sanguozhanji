local PlayScene = class("PlayScene", cc.load("mvc").ViewBase)

local GameView = import(".GameView")

function PlayScene:onCreate( ... )
	self.gameView_ = GameView:create()
		:addTo(self)
end

return PlayScene