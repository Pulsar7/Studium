<div style="text-align:center;">
	<h1>VIM</h1>
	<h3>Keyboard Shortcuts</h3>
</div>

## Insert-Mode

| Key | Description |
|:---:|:------------|
| **b** | Beginning of the word |
| **e** | End of the word |
| **w** | Beginning of the next word |
| **0** | Reach the beginning of the line |
| **$** | Reach the end of the line |
| **o** or **O** | Insert text into a new line |
| **esc** | Switch to *normal-mode* |

## Normal-Mode

| Key | Description |
|:---:|:------------|
| **x** or **X** | Remove a character |
| **r** | Replace one word under the cursor |
| **d** | Delete command |
| **.** | Repeat the previous command |
| **i** or **I** | Switch to *insert-mode* |
| **a** or **A** | Append |
| **yy** | Copy current line |
| **p** | Paste copied text after cursor |
| **w** or **b** or **e** or **ge** | Move word at a time |
| **;** or **,** | Repeat last *f* or *F* |
| **D** | Delete to end of line |
| **S** | Clear current line and changes to *insert-mode* |


## Examples


### Normal-Mode

- Remove two words with `dwd` (and repeat this command with `.`)
- Use `:w` to save
- Use `:q` to quit
- Use `:q!` to quit without saving
- Press `u` for undo
- Press `CTRL+R` for redo
- Use `:help` for help
- Use `/yourtext` and then `n` or `N` to search for a text

