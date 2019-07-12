# RingBuffer
A super simple ring buffer, that can be used on any paltfome (with some edits).
This is tested on simple embedded systems and a simple code on linux.

There are two ways to handle overflow
- Ignore the lastest input
- Ovewrite the oldest data

Both the methods can be used by setting the overflow mehod in the call to the init method.

