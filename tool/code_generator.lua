-- Example:
-- generate_cube_move("R",
-- "(R0 R2 R8 R6)(R1 R5 R7 R3)(U8 B0 D8 F8)(U2 B6 D2 F2)(U5 B3 D5 F5)")
local generate_cube_move = function (op, str)
   local generate_permutation_code = function (str)
      local parse_cyclic_notation = function (str)
         local data = {}
         str:gsub("([FBUDLR])([0-8])",
                  function (x, y) data[#data+1] = {x, y} end)
         return data
      end
      local data = parse_cyclic_notation(str)
      return string.format([[

  // %s
  tmp = cube->%s[%s];
  cube->%s[%s] = cube->%s[%s];
  cube->%s[%s] = cube->%s[%s];
  cube->%s[%s] = cube->%s[%s];
  cube->%s[%s] = tmp;]], str,
         data[4][1], data[4][2],
         data[4][1], data[4][2], data[3][1], data[3][2],
         data[3][1], data[3][2], data[2][1], data[2][2],
         data[2][1], data[2][2], data[1][1], data[1][2],
         data[1][1], data[1][2])
   end
   local data = {}
   str:gsub("%([FBUDLR0-9 ]*%)",
            function (x) data[#data+1] = generate_permutation_code(x) end)
   return string.format([[extern void
cube_move_%s (cube_t *cube)
{
  char tmp;%s
}]], op, table.concat(data))
end
