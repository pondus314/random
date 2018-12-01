local self = {}
--Whole file made by me
function self:initialise()
   self.x = 0
   self.y = 840
   self.w = 48
   self.h = 48
   self.pass = true
   self.action = nil
   self.tleft = 0
   self.side = 1
   self.score = 0
   self.actions = {
      [1] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jumpy boots'
      },
      [2] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jumpy boots'
      },
      [3] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jumpy boots'
      },
      [4] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jumpy boots'
      },
      [5] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jumpy boots'
      }
   }

end

function self:draw()
   love.graphics.setColor(0, 1, 0.5)
   love.graphics.rectangle('fill', self.x, self.y, self.w, self.h)
end

function nothing()
   self.pass = false
end

function jump()
   self.pass = false
   self.x = self.x + 16 * self.side
   if self.x < 0 or self.x > 480-48 then
      self.tleft = 0
      self.x = self.x - 16*self.side
      self.side = self.side * (-1)
      return
   end
end

function flurry()
   for i=#actives, 1, -1 do
      if actives[i]['type']=='Flurry' then
         actives[i]['x'] = self.x+4
         goto noflurry
      end
   end
   table.insert(actives, {['type'] = 'Flurry', ['x'] = self.x+4, ['y'] = self.y - self.h /3, ['w'] = self.w-8, ['h'] = self.h / 3})
   ::noflurry::
end

function boom()
   for i=#objects, 1, -1 do
      table.remove(objects, 1)
   end
end

function flip()
   if math.random() < 0.5 then
      for i=#objects, 1, -1 do
         objects[i].x = 440 - objects[i].x
      end
   else
      self.x = 480-48-self.x
   end
end

return self
