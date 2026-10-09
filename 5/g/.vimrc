augroup LocalNoNumber
  autocmd!
  autocmd BufReadPost,BufNewFile * setlocal nonumber
  autocmd BufReadPost,BufNewFile * setlocal norelativenumber
augroup END
