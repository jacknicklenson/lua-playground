local lib = {}
Meta = {}
Meta.Ver = "SemVer"
Ver = "3.2.1"
function Xprintf(name)
  print("FROM LUA " .. name)
end
lib.ver = "2.3.1";
lib.parse = function (filename)
  local file = io.open(filename,"r")
  io.input(file)
  for l in io.lines() do
    print("TEST" .. l)
  end
  print("==========================================================================")
  file:seek("set", 0)
  local found_text = io.read("a")
  print(found_text)
  -- local i, j = string.find(found_text, "view_split_cnr")
  -- if i == nil or j ==nil then
  --   print("string not found\n")
  -- else
  --   print(string.sub(found_text, i,j))
  -- end
  -- print(io.read(3))
  print("==========================================================================")
  file:seek("set", 0)
  print(file:read(3))
  print(os.getenv("HOME") .. ", " .. os.getenv("USER") .. ", " .. os.getenv("SHELL"))
  print(os.tmpname())
  io.close(file)
end

Foo = {34, 32, 90}

c_func()
local a, b = c_func2(1998, 2)
print("FROM LUA c_func2 = ", a, b)

function Printf_C_struct(c_struct)
  print("C_struct.x = ",c_struct.x)
  print("C_struct.name = ",c_struct.name)
end

return lib
