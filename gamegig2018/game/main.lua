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

function love.load()
   math.randomseed(os.time())
   love.window.setMode(400, 1080, {fullscreen=true})

   gameover = false

   button = {}
   button.down = false
   button.held = false
   button.lift = false

   Player:setup()

   walls = {}
   table.insert(walls, {['x'] = 0, ['y'] = 0, ['w'] = 720, ['h'] = 1080 })
   table.insert(walls, {['x'] = 1200, ['y'] = 0, ['w'] = 720, ['h'] = 1080 })

   objects = {}

   actions = {
      [1] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jump'
      },
      [2] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jump'
      },
      [3] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jump'
      },
      [4] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jump'
      },
      [5] = {
         ['action'] = jump,
         ['time'] = 1000,
         ['name'] = 'Jump'
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

   if button.down and not button.held and Player.pass then
      if #actions then
         if actions[1] then
            Player.action = actions[1]['action']
            Player.tleft = actions[1]['time']
         end
         table.remove(actions,1)
      end
   end

   if (Player.action) then
      Player.tleft=Player.tleft-1
      Player.action()
      if Player.tleft==0 then
         Player.action = nil
         Player.pass = true
      end
   end

   if math.random() < 0.02 then
      if math.random() < 0.9 then
         if math.random() < 0.5 then
            table.insert(objects, {['y']=-20, ['x'] = 720, ['w'] = 40, ['h'] = 40, ['type'] = 'act', ['action'] = jump, ['time'] = 1000})
         else
            table.insert(objects, {['y']=-20, ['x'] = 1160, ['w'] = 40, ['h'] = 40, ['type'] = 'act', ['action'] = jump, ['time'] = 1000})
         end
      else
         if math.random() < 0.5 then
            table.insert(objects, {['y']=-20, ['x'] = 720, ['w'] = 40, ['h'] = 40, ['type'] = 'obst'})
         else
            table.insert(objects, {['y']=-20, ['x'] = 1160, ['w'] = 40, ['h'] = 40, ['type'] = 'obst'})
         end
      end
   end

   for i = #objects, 1, -1 do
      objects[i].y = objects[i].y+4
   end

   for i = #objects, 1, -1 do
      object = objects[i]
      if CheckCollision(Player, object) then
         if object['type']=='obst' then
            gameover = true
         else
            if object['type']=='act' then
               table.insert(actions, {['action']=object['action'], ['time'] =object['time']})
               table.remove(objects, i)
            end
         end
      end
   end

end

function love.draw()
   if not gameover then
      love.graphics.setBackgroundColor(0.1,0,0.05)
      love.graphics.setColor(0, 1, 0.5)
      love.graphics.rectangle('fill', Player.x, Player.y, Player.w, Player.h)
      love.graphics.setColor(0, 0, 0)

      for i=#walls, 1, -1 do
         wall = walls[i]
         love.graphics.rectangle('fill', wall.x, wall.y, wall.w, wall.h)
      end

      for i=#objects, 1, -1 do
         object = objects[i]
         if object['type']=='obst' then
            love.graphics.setColor(1, 0, 0)
         else
            love.graphics.setColor(0, 0, 1)
         end
         love.graphics.rectangle('fill', object.x, object.y, object.w, object.h)
      end

      love.graphics.setColor(1, 1, 1)
      love.graphics.print(Player.side, 960, 400)
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
   Player.x = Player.x + 8 * Player.side
   for i=#walls, 1, -1 do
      wall = walls[i]
      if CheckCollision(Player, wall) then
         Player.tleft = 0
         Player.x = Player.x - 8*Player.side
         Player.side = Player.side * (-1)
         return
      end
   end
end
