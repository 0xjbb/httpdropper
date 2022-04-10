## HTTP Dropper

Created purely to bypass defender inside the HTB ProLab Cybernetics.

- Doesn't make any attempt to hide the console window. 
- Downloads raw shellcode (cobalt beacon, sliver shellcode) via HTTP, I'd recommend switching it to HTTPS
- Uses CreateThread, so change that to something better.
- Makes some effort to evade AV, but not much.

Probably wont update this anymore but you can use it as a base to start.