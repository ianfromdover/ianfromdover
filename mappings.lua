local M = {}

-- In order to disable a default keymap, use
M.disabled = {
  n = {
      -- ["<leader>h"] = "",
      -- ["<C-a>"] = ""
  }
}

-- Your custom mappings
M.abc = {
  n = { -- normal mode
     -- ["<C-n>"] = {"<cmd> Telescope <CR>", "Telescope"},
     -- ["<C-s>"] = {":Telescope Files <CR>", "Telescope Files"},
  },

  i = { -- insert mode
     [",."] = { "<ESC>", "escape insert mode" , opts = { nowait = true }},
  }
}

return M

