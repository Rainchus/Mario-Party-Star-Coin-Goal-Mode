import subprocess

c_file = "main.c"
lst_file = "include/mp4.us.lst"

process = subprocess.Popen(
    ["python", "./c_to_codewrite.py", f"{c_file}", f"{lst_file}"],
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE
)

stdout, stderr = process.communicate()
print(stdout.decode())  # Output of the command
print(stderr.decode())  # Errors (if any)

# Step 2: Replace ending `blr` with `li r31,0` which is the instruction the hook overwrites
file_path = "main.s"
search_text = "\tblr\n\t.size\tminigameListLoadHook, .-minigameListLoadHook"
replace_text = "\tli r31,0\n\t.size\tminigameListLoadHook, .-minigameListLoadHook"

# Read the file
with open(file_path, "r", encoding="utf-8") as file:
    content = file.read()

# Replace the target sequence
new_content = content.replace(search_text, replace_text)

# Write back the modified content
with open(file_path, "w", encoding="utf-8") as file:
    file.write(new_content)

print("blr -> li r31,0")