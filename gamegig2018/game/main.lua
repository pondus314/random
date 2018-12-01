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

   button = {}
   button.down = false
   button.held = false
   button.lift = false

   Player:setup()

   walls = {}
   table.insert(walls, {['x'] = 0, ['y'] = 0, ['w'] = 720, ['h'] = 1080 })
   table.insert(walls, {['x'] = 1200, ['y'] = 0, ['w'] = 720, ['h'] = 1080 })

   actions = {
      [1] = {
         ['action'] = jump,
         ['time'] = 1000
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
      actcount=actcount+1
         if actions[actcount] then
            Player.action = actions[actcount]['action']
            Player.tleft = actions[actcount]['time']
         end
      actcount = actcount % #actions
   end

   if (Player.action) then
      Player.tleft=Player.tleft-1
      Player.action()
      if Player.tleft==0 then
         Player.action = nil
         Player.pass = true
      end
   end

end

function love.draw()

   love.graphics.setBackgroundColor(0.1,0,0.05)
   love.graphics.setColor(0, 1, 0.5)
   love.graphics.rectangle('fill', Player.x, Player.y, Player.w, Player.h)
   love.graphics.setColor(0, 0, 0)

   for i=#walls, 1, -1 do
      wall = walls[i]
      love.graphics.rectangle('fill', wall.x, wall.y, wall.w, wall.h)
   end

   love.graphics.setColor(1, 1, 1)
   love.graphics.print(Player.side, 960, 400)
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
