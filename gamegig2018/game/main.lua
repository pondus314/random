function CheckCollision(rect1, rect2)
   x1 = rect1.x
   y1 = rect1.y
   w1 = rect1.w
   h1 = rect1.h

   x2 = rect2.x
   y2 = rect2.y
   w2 = rect2.w
   h2 = rect2.h

   return x1 < x2+w2 and
         x2 < x1+w1 and
         y1 < y2+h2 and
         y2 < y1+h1
end

local Player = require "player"
screenHeight = 1080
screenWidth = 1920

function love.load()
   math.randomseed(os.time())
   -- love.window.setMode(400, 1080, {fullscreen=true})

   gameover = false

   button = {}
   button.down = false
   button.held = false
   button.lift = false

   Player:initialise()

   walls = {}
   table.insert(walls, {['x'] = 0, ['y'] = 0, ['w'] = 720, ['h'] = 1080 })
   table.insert(walls, {['x'] = 1200, ['y'] = 0, ['w'] = 720, ['h'] = 1080 })

   objects = {}
   objecttimer = 0

   actives = {}

   actions = {
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


   actcount = 0
end

function love.update()
   button.held = love.keyboard.isDown('space') and
               button.down
   button.lift = not love.keyboard.isDown('space') and
               button.down
   button.down = love.keyboard.isDown('space')

   if not gameover then

      if (Player.action) then
         if Player.action==flurry and not button.held then
            Player.tleft = 1
         end
      end

      if button.down and not button.held and Player.pass then
         if #actions then
            if actions[1] then
               Player.action = actions[1]['action']
               Player.tleft = actions[1]['time']
            end
            table.remove(actions,1)
         end
      end


      Player.score = Player.score +1
      if (Player.action) then
         Player.tleft=Player.tleft-1
         Player.action()
         if Player.tleft==0 then
            if #actives > 0 then
               table.remove(actives, 1)
            end
            Player.action = nil
            Player.pass = true
         end
      end

      if objecttimer > 0 then
         objecttimer = objecttimer - 1
      end

      if math.random() < 0.1 and objecttimer==0 then
         table.insert(objects, {['y']=-20, ['w'] = 40, ['h'] = 40})
         if math.random() < 0.5 then
            objects[#objects]['x'] = 720
         else
            objects[#objects]['x'] = 1160
         end
         if math.random() < 0.2 and #actions < 10 then
               objects[#objects]['type'] = 'act'
               local type = math.random()
               if type < 0.4 then
                  objects[#objects]['action'] = jump
                  objects[#objects]['time'] = 1000
                  objects[#objects]['number'] = 3
                  objects[#objects]['name'] = 'Jumpy boots'
               end
               if type >= 0.4 and type < 0.6 then
                  objects[#objects]['action'] = flurry
                  objects[#objects]['time'] = 200
                  objects[#objects]['number'] = 1
                  objects[#objects]['name'] = 'Sword'
               end
               if type >= 0.6 and type < 0.7 then
                  objects[#objects]['action'] = boom
                  objects[#objects]['time'] = 1
                  objects[#objects]['number'] = 1
                  objects[#objects]['name'] = 'Explosives'
               end
               if type >= 0.7 and type < 0.9 then
                  objects[#objects]['action'] = flip
                  objects[#objects]['time'] = 1
                  objects[#objects]['number'] = 1
                  objects[#objects]['name'] = 'Invertor'
               end
               if type > 0.9 then
                  objects[#objects]['action'] = nothing
                  objects[#objects]['time'] = 40
                  objects[#objects]['number'] = 1
                  objects[#objects]['name'] = 'Red Herring'
               end
               if math.random() < 0.05 then
                  objects[#objects]['name'] = 'Random'
               end
         else
            objects[#objects]['type'] = 'obst'
         end
         objecttimer = 25
      end --object creation

      for i = #objects, 1, -1 do
         objects[i].y = objects[i].y+ 4 * math.max(math.log(Player.score/800)+1, 1)
      end --object movement

      for i = #objects, 1, -1 do
         local object = objects[i]
         local exists = true
         for j = #actives, 1, -1 do
            local active = actives[j]
            if CheckCollision(active, object) then
               table.remove(objects,i)
               exists = false
               goto continue
            end
         end

         if CheckCollision(Player, object) then
            if object['type']=='obst' then
               gameover = true
            else
               if object['type']=='act' then
                  for i = object['number'], 1, -1 do
                     table.insert(actions, {['action']=object['action'], ['time'] =object['time'], ['name'] = object['name']})
                  end
                  table.remove(objects, i)
               end
            end
         end

         if object.y > screenHeight then
            table.remove(objects, i)
         end
         ::continue::
      end --player/object collision

   end

end

function love.draw()
   if not gameover then
      love.graphics.setBackgroundColor(0.1,0,0.05)
      love.graphics.setColor(0, 1, 0.5)
      love.graphics.rectangle('fill', Player.x, Player.y, Player.w, Player.h)
      love.graphics.setColor(0, 0, 0)

      for i=#walls, 1, -1 do
         local wall = walls[i]
         love.graphics.rectangle('fill', wall.x, wall.y, wall.w, wall.h)
      end --walls drawing

      for i=#objects, 1, -1 do
         local object = objects[i]
         if object['type']=='obst' then
            love.graphics.setColor(1, 0, 0)
         else
            love.graphics.setColor(0, 0, 1)
         end
         love.graphics.rectangle('fill', object.x, object.y, object.w, object.h)
      end --object drawing

      for i=#actives, 1, -1 do
         local active = actives[i]
         if active['type']=='Flurry' then
            love.graphics.setColor(0.1, 0.1, 0.1)
            love.graphics.rectangle('fill', active.x, active.y, active.w, active.h)
         end
      end --actives drawing

      love.graphics.setColor(1, 1, 1)
      for i=#actions, 1, -1 do
         local name = actions[i]['name']
         love.graphics.print(name, 120, 40+i*10)
      end

      love.graphics.print(Player.score..'  '..love.timer.getFPS(), 960, 200)

   else
      love.graphics.setBackgroundColor(0.1,0,0.05)
      love.graphics.print("gameover", 960, 400)
   end
end

function nothing()
   Player.pass = false
end

function jump()
   Player.pass = false
   Player.x = Player.x + 16 * Player.side
   for i=#walls, 1, -1 do
      local wall = walls[i]
      if CheckCollision(Player, wall) then
         Player.tleft = 0
         Player.x = Player.x - 16*Player.side
         Player.side = Player.side * (-1)
         return
      end
   end
end

function flurry()
   for i=#actives, 1, -1 do
      if actives[i]['type']=='Flurry' then
         actives[i]['x'] = Player.x+4
         goto noflurry
      end
   end
   table.insert(actives, {['type'] = 'Flurry', ['x'] = Player.x+4, ['y'] = Player.y - Player.h /3, ['w'] = Player.w-8, ['h'] = Player.h / 3})
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
         objects[i].x = 1880 - objects[i].x
      end
   else
      Player.x = 1920-48-Player.x
   end
end
