/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */
 
//---Piece Starts to Fall When Game Starts---//
void fallingPiece(float& timer, float& delay, int& colornum){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }                                     
        if (!anamoly()){
        	for(int i=0; i<4; i++)
        		gameGrid[point_2[i][1]][point_2[i][0]]= colornum;
        		
        	colornum=1+rand()%7;   ///randomly assigning color
            int n=rand()%7;			// randomly selecting a block from the seven blocks
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
            for (int i=0;i<4;i++){
            	point_1[i][0] = BLOCKS[n][i] % 2;
            	point_1[i][1] = BLOCKS[n][i] / 2;
                }
            
        }
        
        timer=0;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

// function to move left or right
void moveLeftRight(int& delta_x,int& colornum)
{
	
	for(int i =0; i<4; i++)
		{
		if (gameGrid[point_1[i][1]][point_1[i][0] + 1] != 0)	//// checking for other blocks on left and right
			delta_x = 0;
		else if (gameGrid[point_1[i][1]][point_1[i][0] - 1] != 0)
			delta_x = 0;
		}
	
	//// Checking for walls
	for(int i=0; i<4; i++)	
        {if (point_1[i][0]<0) 
            delta_x = 1;
		if (point_1[i][0]>=(N))
			delta_x = -1;}
	
	if(delta_x == 1 || delta_x == -1)
	{
		for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][0]+=delta_x;                   //How much units right or left
      		}
     }
}

////// Rotation function
void Rotate()

{
		for(int i =0; i< 4; i++)
		{	
			int x = point_1[i][1] - point_1[1][1];
			int y = point_1[i][0] - point_1[1][0];
			point_1[i][0] = point_1[1][0] - x;
			point_1[i][1] = point_1[1][1] + y;
		}
}


//////// destroy lines
void destroyLines()
{
	bool lines_removed = 0;
	for(int i =0; i<M; i++)
	{ int counter =0;
		for(int j=0; j<N; j++)
		{
			if (gameGrid[i][j] != 0)   ////// checking if a line is full
				counter += 1;
		}
		if(counter == 10)
		{
			for(int j=0; j<N; j++)
			{
				gameGrid[i][j] =0;     //////// removing the line
			}
			lines_removed = 1;
		}
	}
	if(lines_removed)
	{
		for(int i =M; i>0; i--)
		{
			for(int j =0; j<N; j++)
			{
				gameGrid[i][j] = gameGrid[i-1][j];     ///////// bringing the game down
			}
		}
	}
	lines_removed = 0;
}


///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
