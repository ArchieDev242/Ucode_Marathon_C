  #include "../inc/header.h"

  bool path(int **grid,int ax, int ay, int bx, int by, int He, int Wi, int *len,int *pathX,int *pathY)
  {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int d, x, y, k;
    bool check;

    if(grid[ay][ax] == -1 ) 
    {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(0);
    }

    if(grid[by][bx] == -1 ) 
    {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(0);
    }

    d = 0;
    grid[ay][ax] = 0;

    while(true) 
    {
      check = true;
      for( y = 0; y < He; ++y )
        for( x = 0; x < Wi; ++x )
          if( grid[y][x] == d )
          {
            for( k = 0; k < 4; ++k )
            {
              int iy=y + dy[k], ix = x + dx[k];

              if( iy >= 0 && iy < He && ix >= 0 && ix < Wi && grid[iy][ix] == -2 )
              {
                  check = false;
                  grid[iy][ix] = d + 1;
              }
            }
          }
      d++;
      if(( check || grid[by][bx] != -2 )) break;
    } 

    if(grid[by][bx] == -2) return false;

    *len = grid[by][bx];
    x = bx;
    y = by;
    d = *len;

    while( d > 0 )
    {
      pathX[d] = x;
      pathY[d] = y;
      d--;
      for (k = 0; k < 4; ++k)
      {
        int iy=y + dy[k], ix = x + dx[k];

        if( iy >= 0 && iy < He && ix >= 0 && ix < Wi && grid[iy][ix] == d)
        {
            x = x + dx[k];
            y = y + dy[k];
            break;
        }
      }
    }

    pathX[0] = ax;
    pathY[0] = ay;
    
    return true;
  }
  
