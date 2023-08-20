# Logic Gates Game
A simple educational game that aims to help people learn different logic gates. Uses a mobile application that is very easy to use.

To use the app go to MIT app inventor and import the (.aia) file, then build->android app (.apk), then scan the qr code. 

The app has 2 modes: 
   
    1 - Learn: 
        You can see that the screen is split into 3 parts above each other, the bottom part contains buttons with the names 
        of the logic gates, the middle part contains a truth table, and the upper part contains an unknown logic gate in the
        middle and 2 buttons on the left side act as input and on the right side a button acts as output.
        The scenario goes as follows: first, you choose a gate from the bottom part, then the unknown gate in the upper will
        change into the chosen gate and the truth table will be the truth table of the chosen gate, then you can change the
        inputs as you want and see the output change according to the truth table.
        
    2 - Test yourself:
        once you hit the "test yourself" button, a random test will appear in front of you.
        The screen will be split into 2 parts:
            - unknown gate with its input and output
            - 4 options to choose from
        Toogle the input buttons and observe the output in each case then choose the desired gate. If you fail to guess 
        the correct gate, you will know the correct choice then you'll have another test and if you pass, you will return
        to the home screen again. 

In both modes, every time the input buttons or the output changes, the app sends a request to the nodeMCU to change the led states in of the real components.
