# devcon

A demo on the usage of Development Containers in VS Code

Getting started:

* Install the dev container plug in from Microsoft into VS Code
* Run command: 'Dev Container: Rebuild'
* Set the IP address of the pi in .vscode/settings.json and safe
* Run Task: 'Set SSH key for Raspberry Pi'
  * Some questions need to be answered interactively. Just press enter on all except password question.
* Run task: 'Build, Deploy and Run'
  * The application should now run on the pi and you should see the output
* Debug the application by 
  * Select Run and Debug
  * Select 'Remote Debug Raspberry Pi'
  * Set a breakpoint on an interesting line
  * Start debugging (or press F5)