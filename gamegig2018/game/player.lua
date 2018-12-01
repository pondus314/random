local player = {}

function player:initialise()
   self.x = 720
   self.y = 840
   self.w = 48
   self.h = 48
   self.pass = true
   self.action = nil
   self.tleft = 0
   self.side = 1
   self.score = 0
end

return player
