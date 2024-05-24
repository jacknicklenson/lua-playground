function love.draw()
  love.graphics.print("Hello World!", 400, 300)
  love.graphics.arc("line", 300, 300, 10, 0, 360, 10)
  love.graphics.draw(Ps, love.mouse.getX(), love.mouse.getY())
end

function love.load()
  local img = love.graphics.newImage("explosion.jpg")
  Ps = love.graphics.newParticleSystem(img)
  Ps:setParticleLifetime(0.1, 1)
  Ps:setEmissionRate(3)
  Ps:setSpread(4)
  Ps:setSpin(1, 30)
  Ps:setSpinVariation(1)
end

function love.update(dt)
  Ps:update(dt)
end
