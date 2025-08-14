
# Description:
- This program allows you to create shapes on the screen, as well as work with them as a whole. 
- Interaction with the program is carried out via the command line. 
- The user enters commands, after which the graphics are displayed in the window. 
- By pressing the S key, it is possible to save the current state of the graphic window to a .png file.

# Set of supported commands:
1) ```AddShape <id> <color> <type> <parameters> ```
Adds a shape (rectangle, triangle or circle) to the Picture, but does not display it. 
2) ```MoveShape <id> <dx> <dy>``` 
Shifts the specified shape along the vector (dx, dy)
3) ```MovePicture <dx> <dy>```
Shifts the entire composition along the vector (dx, dy), as if the ```MoveShape``` command were applied to all the shapes of the composition.
4) ```DeleteShape <id>```
Deletes a shape with the specified id
5) ```List```
Displays a list of shapes. The shapes are displayed in the order they are added.
6) ```ChangeColor <id> <color>```
The changeColor command changes the color of the shape.
7) ChangeShape <id> <type> <parameters>
The ChangeShape command changes the shape type and its parameters. The color and ID of the shape of the shape remains unchanged.
8) ```DrawShape <id>```
Draws a shape with the specified id.
9) ```DrawPicture```
Draws all the shapes of the composition from the first to the last

- To learn more about the commands, as well as to find examples, see the documentation section.


# Program architecture:
