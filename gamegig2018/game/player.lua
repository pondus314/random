local player = {}

function player:setup()
   self.x = 960
   self.y = 540
   self.w = 48
   self.h = 48
   self.pass = true
   self.action = nil
   self.tleft = 0
   self.side = 1
end

return player
