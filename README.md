
# Description:
- This program allows you to create shapes on the screen, as well as work with them as a whole. 
- Interaction with the program is carried out via the command line. 
- The user enters commands, after which the graphics are displayed in the window. 
- By pressing the S key, it is possible to save the current state of the graphic window to a .png file.

# Set of supported commands:
1) ✅    ```AddShape <id> <color> <type> <parameters> ``` 
Adds a shape (rectangle, triangle or circle) to the Picture, but does not display it. 
2) ✅       ```MoveShape <id> <dx> <dy>``` 
Shifts the specified shape along the vector (dx, dy)
3) ✅       ```MovePicture <dx> <dy>```
Shifts the entire composition along the vector (dx, dy), as if the ```MoveShape``` command were applied to all the shapes of the composition.
4) ✅           ```DeleteShape <id>```
Deletes a shape with the specified id
5) ✅   ```List```
Displays a list of shapes. The shapes are displayed in the order they are added.
6) ```ChangeColor <id> <color>```
The changeColor command changes the color of the shape.
7) ```ChangeShape <id> <type> <parameters>```
The ChangeShape command changes the shape type and its parameters. The color and ID of the shape of the shape remains unchanged.
8) ```DrawShape <id>```
Draws a shape with the specified id.
9) ✅        ```DrawPicture```
Draws all the shapes of the composition from the first to the last

__Atention! Comands  ```AddShape```, ```MoveShape```, ```DeleteShape``` change the state of the Picture's data, but not display new graphics. To redraw Picture with new state, execude ```DrawPicture``` command.__

- The sign ✅ shows thas this command is supported now, if the sign is not with command, it's not supported now

- To learn more about the commands, as well as to find examples, see the documentation section.

# Set of supported shapes:

#### 1.Circle

- The circle is set by the coordinates of the center and the radius. All parameters are floating point numbers. The radius must be non-negative.

```txt
circle <x> <y> <r>
```

Example:

```txt
AddShape circ #febb38 circle 100 200 25
```

#### 2. Rectangle

- The rectangle is defined by the coordinates of the upper-left corner, width and height. All parameters are floating point numbers.
The width and height must be non-negative.

```txt
rectangle <left> <top> <width> <height>
```

Example:

```txt
AddShape sh1 #123456 rectangle 10 20 30 40
```

#### 3. Triangle

- The triangle is defined by the coordinates of the vertices. All numbers are floating—point parameters.

```txt
triangle <x1> <y1> <x2> <y2> <x3> <y3>
```

Example:

```txt
AddShape tr1 #00fefe triangle 0 0 10 0 0 10
```

#### 4. Straight line segment

- A straight line segment is defined by the coordinates of the beginning and end.

```txt
line <x1> <y1> <x2> <y2>
```

Example:

```txt
AddShape ln1 #fefefe line 10 20 35 -88
```

#### 5. Text block 

- The text is set by the coordinates of the upper-left corner, the font size, and the text of the label. The text coordinates and font sizes are floating—point numbers. The size must be non-negative. Text is a string of characters up to the end of the line.

```txt
text <left> <top> <size> <test>
```

Example:

```txt
AddShape txt1 #ffaa88 text 100.3 100.2 12.8 Hello world
```

# Program architecture:
