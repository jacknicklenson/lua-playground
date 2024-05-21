local parser = require("lib")

parser.parse("log.txt")
Xprintf()
local mytable = setmetatable({ 1, 2, 3 }, {
   __add = function(mytable, newtable)
      for i = 1, #newtable do
         table.insert(mytable, #mytable+1,newtable[i])
      end
      return mytable
   end
})

function mytable.cnaer()
  print("hello")
end

local secondtable = {4,5,6}

mytable = mytable + secondtable
mytable.cnaer()
for k,v in ipairs(mytable) do
   print(k,v)
end

for k=1, #mytable do
   print(mytable[k])
end
