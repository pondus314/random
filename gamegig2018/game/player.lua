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

function player:draw()
   love.graphics.setColor(0, 1, 0.5)
   love.graphics.rectangle('fill', self.x, self.y, self.w, self.h)
end

function player:update()
   self.score = self.score +1
   if (self.action) then
      self.tleft=self.tleft-1
      self.action()
      if self.tleft==0 then
         if #actives > 0 then
            table.remove(actives, 1)
         end
         self.action = nil
         self.pass = true
      end
   end
end

return player
