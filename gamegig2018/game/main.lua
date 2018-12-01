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

local DESIRED_WIDTH = 480
local DESIRED_HEIGHT = 1080

local love = love
local LogicalScale = {
	-- Current screen dimension
	ScreenX = DESIRED_WIDTH,
	ScreenY = DESIRED_HEIGHT,
	-- Letterboxing offset
	OffX = 0,
	OffY = 0,
	-- Overall letterboxing scaling
	ScaleOverall = 1
}

local function CalculateTouchPosition(x, y)
	return
		(x - LogicalScale.OffX) / LogicalScale.ScaleOverall,
		(y - LogicalScale.OffY) / LogicalScale.ScaleOverall
end

function love.load()
	--[[
		My code starts HERE
	]]--

   math.randomseed(os.time())
   -- love.window.setMode(400, 1080, {fullscreen=true})

   gameover = false

   button = {}
   button.down = false
   button.held = false
   button.lift = false

   Player:initialise()

   objects = {}
   objecttimer = 0

   actives = {}

   fonts = {}
   fonts.small = love.graphics.newFont("assets/fonts/Eastdokdo.ttf", 32)
   fonts.medium = love.graphics.newFont("assets/fonts/Eastdokdo.ttf", 64)
   fonts.large = love.graphics.newFont("assets/fonts/Eastdokdo.ttf", 128)
   fonts.huge = love.graphics.newFont("assets/fonts/Eastdokdo.ttf", 256)


   --[[
		And it ends HERE
	]]--

   actcount = 0

	LogicalScale.ScreenX, LogicalScale.ScreenY = love.graphics.getDimensions()
	LogicalScale.ScaleOverall = math.min(
		LogicalScale.ScreenX / DESIRED_WIDTH,
		LogicalScale.ScreenY / DESIRED_HEIGHT
	)
	LogicalScale.OffX = (LogicalScale.ScreenX - LogicalScale.ScaleOverall * DESIRED_WIDTH) / 2
	LogicalScale.OffY = (LogicalScale.ScreenY - LogicalScale.ScaleOverall * DESIRED_HEIGHT) / 2
end

function love.resize(w, h)
	LogicalScale.ScreenX, LogicalScale.ScreenY = w, h
	LogicalScale.ScaleOverall = math.min(
		LogicalScale.ScreenX / DESIRED_WIDTH,
		LogicalScale.ScreenY / DESIRED_HEIGHT
	)
	LogicalScale.OffX = (LogicalScale.ScreenX - LogicalScale.ScaleOverall * DESIRED_WIDTH) / 2
	LogicalScale.OffY = (LogicalScale.ScreenY - LogicalScale.ScaleOverall * DESIRED_HEIGHT) / 2
end

function love.update() --All mine
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
         if #Player.actions then
            if Player.actions[1] then
               Player.action = Player.actions[1]['action']
               Player.tleft = Player.actions[1]['time']
            end
            table.remove(Player.actions,1)
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
            objects[#objects]['x'] = 0
         else
            objects[#objects]['x'] = 440
         end
         if math.random() < 0.2 and #Player.actions < 10 then
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
                     table.insert(Player.actions, {['action']=object['action'], ['time'] =object['time'], ['name'] = object['name']})
                  end
                  table.remove(objects, i)
               end
            end
         end

         if object.y > DESIRED_HEIGHT then
            table.remove(objects, i)
         end
         ::continue::
      end --player/object collision

   end

end

function love.draw()
	love.graphics.push("all")

	love.graphics.translate(LogicalScale.OffX, LogicalScale.OffY)
	love.graphics.scale(LogicalScale.ScaleOverall, LogicalScale.ScaleOverall)

	--[[
		MY CODE STARTS HERE
	]]--

   if not gameover then
      love.graphics.setColor(0.1,0,0.05)

      love.graphics.rectangle('fill',0, 0, 480, 1080)

      Player:draw()

      love.graphics.setColor(0, 0, 0)

      -- for i=#walls, 1, -1 do
      --    local wall = walls[i]
      --    love.graphics.rectangle('fill', wall.x, wall.y, wall.w, wall.h)
      -- end --walls drawing


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
      for i=#Player.actions, 1, -1 do
         local name = Player.actions[i]['name']
         if i==1 then
            love.graphics.setColor(0, 1, 0.5)
         else
            love.graphics.setColor(1, 1, 1)
         end
         love.graphics.setFont(fonts.small)
         love.graphics.print(name, (480-(fonts.small:getWidth(name)))/2, 256+i*32)
      end

      love.graphics.setColor(1, 1, 1)
      love.graphics.setFont(fonts.large)
      love.graphics.print(Player.score, (480-(fonts.large:getWidth(Player.score)))/2, 64)

   else
      love.graphics.setBackgroundColor(0.1,0,0.05)
      love.graphics.setFont(fonts.huge)
      love.graphics.print("Game Over", (480-fonts.huge:getWidth("Game over"))/2, 400)
      love.graphics.print("Your score is " .. Player.score, (480-fonts.huge:getWidth("Your score is ")-fonts.huge:getWidth(Player.score))/2, 656)
   end

   --[[
   AND IT ENDS HERE
   ]]--

	love.graphics.pop()
end
