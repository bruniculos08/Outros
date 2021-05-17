// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int averageblue[height][width];
    int averagegreen[height][width];
    int averagered[height][width];
    int na = 1;
    int sb;
    int sg;
    int sr;

    for (int i=0; i<height; i++)
    {

        for (int j=0; j<width; j++)
        {

            BYTE *bco = &image[i][j].rgbtBlue;
            BYTE *gco = &image[i][j].rgbtGreen;
            BYTE *rco = &image[i][j].rgbtRed;

            int b = image[i][j].rgbtBlue;
            int g = image[i][j].rgbtGreen;
            int r = image[i][j].rgbtRed;

            for (int x=-1; x<1; x++)
            {
                for (int y=-1; y<-1; y++)
                {
                    if (x+i >= 0 && y+j >=0 && x+i <= height && y+j <= width)
                    {
                        int bn = image[x+i][y+j].rgbtBlue;
                        int gn = image[x+i][y+j].rgbtGreen;
                        int rn = image[x+i][y+j].rgbtRed;

                        sb = ++bn;
                        sg = ++gn;
                        sr = ++rn;

                        na = +1;
                    }
                }
            }
        averageblue[i][j] = (sb)/na;
        averagegreen[i][j] = (sg)/na;
        averagered[i][j] = (sr)/na;
        na = 0;

        }
    }
    for (int i=0; i<height; i++)
    {
        for (int j=0; j<width; j++)
        {
            BYTE *bco = &image[i][j].rgbtBlue;
            BYTE *gco = &image[i][j].rgbtGreen;
            BYTE *rco = &image[i][j].rgbtRed;

            *bco = averageblue[i][j];
            *gco = averagegreen[i][j];
            *rco = averagered[i][j];

        }
    }
    return;
}





                if ((i=0) && (j=0))
                {
                    newimage[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/3;
                    newimage[i][j].rgbtGreen =(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/3;
                    newimage[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/3;
                }
                if ((i=0) && (j>0) && (j<width-1))
                {
                    newimage[i][j].rgbtBlue = (image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i][j-1].rgbtBlue)/5;
                    newimage[i][j].rgbtGreen = (image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i][j-1].rgbtGreen)/5;
                    newimage[i][j].rgbtRed = (image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i][j-1].rgbtRed)/5;
                }
                if ((j=0) && (i>0) && (i<height-1))
                {
                    newimage[i][j].rgbtBlue = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;
                    newimage[i][j].rgbtGreen = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;
                    newimage[i][j].rgbtRed = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;

                }

































       for (int i=0; i=height-1; i++)
    {
        for (int j=0; j=width-1; j++)

            {

                //newimage[i][j].rgbtBlue = image[i][j].rgbtBlue;
                //newimage[i][j].rgbtGreen = image[i][j].rgbtGreen;
                //newimage[i][j].rgbtRed = image[i][j].rgbtRed;
                //BLUE PIXELS
                //int fib = *image[i-1][j-1].rgbtBlue;
                //int seb = image[i-1][j].rgbtBlue;
                //int thb = image[i-1][j+1].rgbtBlue;
                //int fob = image[i][j-1].rgbtBlue;
                //int fvb = image[i][j].rgbtBlue;
                //int sib = image[i][j+1].rgbtBlue;
                //int svb = image[i+1][j-1].rgbtBlue;
                //int eib = image[i+1][j].rgbtBlue;
                //int nib = image[i+1][j+1].rgbtBlue;

                //GREEN PIXELS
                //int fig = image[i-1][j-1].rgbtGreen;
                //int seg = image[i-1][j].rgbtGreen;
                //int thg = image[i-1][j+1].rgbtGreen;
                //int fog = image[i][j-1].rgbtGreen;
                //int fvg = image[i][j].rgbtGreen;
                //int sig = image[i][j+1].rgbtGreen;
                //int svg = image[i+1][j-1].rgbtGreen;
                //int eig = image[i+1][j].rgbtGreen;
                //int nig = image[i+1][j+1].rgbtGreen;

                //RED PIXELS
                //int fir = image[i-1][j-1].rgbtRed;
                //int ser = image[i-1][j].rgbtRed;
                //int thr = image[i-1][j+1].rgbtRed;
                //int fore = image[i][j-1].rgbtRed;
                //int fvr = image[i][j].rgbtRed;
                //int sir = image[i][j+1].rgbtRed;
                //int svr = image[i+1][j-1].rgbtRed;
                //int eir = image[i+1][j].rgbtRed;
                //int nir = image[i+1][j+1].rgbtRed;

                //canto superior esquerdo
                if ((i=0) && (j=0))
                {
                    BYTE fvb = image[i][j].rgbtBlue;
                    BYTE sib = image[i][j+1].rgbtBlue;
                    BYTE eib = image[i+1][j].rgbtBlue;
                    BYTE nib = image[i+1][j+1].rgbtBlue;

                    BYTE fvg = image[i][j].rgbtGreen;
                    BYTE sig = image[i][j+1].rgbtGreen;
                    BYTE eig = image[i+1][j].rgbtGreen;
                    BYTE nig = image[i+1][j+1].rgbtGreen;

                    BYTE fvr = image[i][j].rgbtRed;
                    BYTE sir = image[i][j+1].rgbtRed;
                    BYTE eir = image[i+1][j].rgbtRed;
                    BYTE nir = image[i+1][j+1].rgbtRed;

                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (fvb+sib+eib+nib)/4;  //(image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/3;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (fvg+sig+eig+nig)/4; //(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/3;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtGreen + (fvr+sir+eir+nir)/4;   //(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/3;
                }

                //borda de cima
                if ((i=0)&&(0<j<width-1))
                {
                    BYTE fob = image[i][j-1].rgbtBlue;
                    BYTE fvb = image[i][j].rgbtBlue;
                    BYTE sib = image[i][j+1].rgbtBlue;
                    BYTE svb = image[i+1][j-1].rgbtBlue;
                    BYTE eib = image[i+1][j].rgbtBlue;
                    BYTE nib = image[i+1][j+1].rgbtBlue;

                    BYTE fog = image[i][j-1].rgbtGreen;
                    BYTE fvg = image[i][j].rgbtGreen;
                    BYTE sig = image[i][j+1].rgbtGreen;
                    BYTE svg = image[i+1][j-1].rgbtGreen;
                    BYTE eig = image[i+1][j].rgbtGreen;
                    BYTE nig = image[i+1][j+1].rgbtGreen;

                    BYTE fore = image[i][j-1].rgbtRed;
                    BYTE fvr = image[i][j].rgbtRed;
                    BYTE sir = image[i][j+1].rgbtRed;
                    BYTE svr = image[i+1][j-1].rgbtRed;
                    BYTE eir = image[i+1][j].rgbtRed;
                    BYTE nir = image[i+1][j+1].rgbtRed;

                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (fvb+fob+svb+eib+nib+sib)/6;  //(image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i][j-1].rgbtBlue)/5;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen +(fvg+fog+svg+eig+nig+sig)/6; //(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i][j-1].rgbtGreen)/5;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (fvr+fore+svr+eir+nir+sir)/6;  //(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i][j-1].rgbtRed)/5;
                }

                //borda da esquerda
                if ((j=0) && (i>0) && (i<height-1))
                {
                    BYTE seb = image[i-1][j].rgbtBlue;
                    BYTE thb = image[i-1][j+1].rgbtBlue;
                    BYTE fvb = image[i][j].rgbtBlue;
                    BYTE sib = image[i][j+1].rgbtBlue;
                    BYTE eib = image[i+1][j].rgbtBlue;
                    BYTE nib = image[i+1][j+1].rgbtBlue;

                    BYTE seg = image[i-1][j].rgbtGreen;
                    BYTE thg = image[i-1][j+1].rgbtGreen;
                    BYTE fvg = image[i][j].rgbtGreen;
                    BYTE sig = image[i][j+1].rgbtGreen;
                    BYTE eig = image[i+1][j].rgbtGreen;
                    BYTE nig = image[i+1][j+1].rgbtGreen;

                    BYTE ser = image[i-1][j].rgbtRed;
                    BYTE thr = image[i-1][j+1].rgbtRed;
                    BYTE fvr = image[i][j].rgbtRed;
                    BYTE sir = image[i][j+1].rgbtRed;
                    BYTE eir = image[i+1][j].rgbtRed;
                    BYTE nir = image[i+1][j+1].rgbtRed;

                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (fvb+seb+thb+sib+nib+eib)/6;  //(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (fvg+seg+thg+sig+nig+eig)/6; //(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (fvr+ser+thr+sir+nir+eir)/6;   //(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;
                }

                //canto inferior esquerdo
                if ((j=0)&&(i=height-1))
                {
                    BYTE seb = image[i-1][j].rgbtBlue;
                    BYTE thb = image[i-1][j+1].rgbtBlue;
                    BYTE fvb = image[i][j].rgbtBlue;
                    BYTE sib = image[i][j+1].rgbtBlue;

                    BYTE seg = image[i-1][j].rgbtGreen;
                    BYTE thg = image[i-1][j+1].rgbtGreen;
                    BYTE fvg = image[i][j].rgbtGreen;
                    BYTE sig = image[i][j+1].rgbtGreen;

                    BYTE ser = image[i-1][j].rgbtRed;
                    BYTE thr = image[i-1][j+1].rgbtRed;
                    BYTE fvr = image[i][j].rgbtRed;
                    BYTE sir = image[i][j+1].rgbtRed;

                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (fvb+thb+seb+sib)/4;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (fvg+thg+seg+sig)/4;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtBlue + (fvr+thr+ser+sir)/4;
                }

                //borda de baixo
                if ((i=height-1)&&(j>0)&&(j<width-1))
                {
                    BYTE fob = image[i][j-1].rgbtBlue;
                    BYTE fvb = image[i][j].rgbtBlue;
                    BYTE sib = image[i][j+1].rgbtBlue;
                    BYTE svb = image[i+1][j-1].rgbtBlue;
                    BYTE eib = image[i+1][j].rgbtBlue;
                    BYTE nib = image[i+1][j+1].rgbtBlue;


                    BYTE fog = image[i][j-1].rgbtGreen;
                    BYTE fvg = image[i][j].rgbtGreen;
                    BYTE sig = image[i][j+1].rgbtGreen;
                    BYTE svg = image[i+1][j-1].rgbtGreen;
                    BYTE eig = image[i+1][j].rgbtGreen;
                    BYTE nig = image[i+1][j+1].rgbtGreen;


                    BYTE fore = image[i][j-1].rgbtRed;
                    BYTE fvr = image[i][j].rgbtRed;
                    BYTE sir = image[i][j+1].rgbtRed;
                    BYTE svr = image[i+1][j-1].rgbtRed;
                    BYTE eir = image[i+1][j].rgbtRed;
                    BYTE nir = image[i+1][j+1].rgbtRed;

                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (fvb+fob+svb+eib+nib+sib)/6;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (fvg+fog+svg+eig+nig+sig)/6;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (fvr+fore+svr+eir+nir+sir)/6;
                }

                //canto superior direito
                if ((i=0)&&(j=width-1))
                {
                    BYTE fob = image[i][j-1].rgbtBlue;
                    BYTE fvb = image[i][j].rgbtBlue;
                    BYTE svb = image[i+1][j-1].rgbtBlue;
                    BYTE eib = image[i+1][j].rgbtBlue;

                    BYTE fog = image[i][j-1].rgbtGreen;
                    BYTE fvg = image[i][j].rgbtGreen;
                    BYTE svg = image[i+1][j-1].rgbtGreen;
                    BYTE eig = image[i+1][j].rgbtGreen;

                    BYTE fore = image[i][j-1].rgbtRed;
                    BYTE fvr = image[i][j].rgbtRed;
                    BYTE svr = image[i+1][j-1].rgbtRed;
                    BYTE eir = image[i+1][j].rgbtRed;

                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (*fvb+*fob+*svb+*eib)/4;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (*fvg+*fog+*svg+*eig)/4;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (*fvr+*fore+*svr+*eir)/4;
                }

                //borda da direita
                if ((j=width-1)&&(i>0)&&(i<height-1))
                {
                    BYTE fib = image[i-1][j-1].rgbtBlue;
                    BYTE seb = image[i-1][j].rgbtBlue;
                    BYTE fob = image[i][j-1].rgbtBlue;
                    BYTE fvb = image[i][j].rgbtBlue;
                    BYTE svb = image[i+1][j-1].rgbtBlue;
                    BYTE eib = image[i+1][j].rgbtBlue;

                    BYTE fig = image[i-1][j-1].rgbtGreen;
                    BYTE seg = image[i-1][j].rgbtGreen;
                    BYTE fog = image[i][j-1].rgbtGreen;
                    BYTE fvg = image[i][j].rgbtGreen;
                    BYTE svg = image[i+1][j-1].rgbtGreen;
                    BYTE eig= image[i+1][j].rgbtGreen;

                    BYTE fir = image[i-1][j-1].rgbtRed;
                    BYTE ser = image[i-1][j].rgbtRed;
                    BYTE fore = image[i][j-1].rgbtRed;
                    BYTE fvr = image[i][j].rgbtRed;
                    BYTE svr = image[i+1][j-1].rgbtRed;
                    BYTE eir = image[i+1][j].rgbtRed;

                   newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (fvb+fob+fib+seb+svb+eib)/6;
                   newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (fvg+fog+fig+seg+svg+eig)/6;
                   newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (fvr+fore+fir+ser+svr+eir)/6;
                }

                //canto inferior direito
                if ((i=height-1)&&(j=width-1))
                {
                    BYTE fib = image[i-1][j-1].rgbtBlue;
                    BYTE seb = image[i-1][j].rgbtBlue;
                    BYTE fob = image[i][j-1].rgbtBlue;
                    BYTE fvb = image[i][j].rgbtBlue;

                    BYTE fig = image[i-1][j-1].rgbtGreen;
                    BYTE seg = image[i-1][j].rgbtGreen;
                    BYTE fog = image[i][j-1].rgbtGreen;
                    BYTE fvg = image[i][j].rgbtGreen;

                    BYTE fir = image[i-1][j-1].rgbtRed;
                    BYTE ser = image[i-1][j].rgbtRed;
                    BYTE fore = image[i][j-1].rgbtRed;
                    BYTE fvr = image[i][j].rgbtRed;

                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (fvb+fob+fib+seb)/4;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtBlue + (fvg+fog+fig+seg)/4;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtBlue + (fvr+fore+fir+ser)/4;
                }
            }
        }




void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE newimage[height][width];
    for (int i=0; i<height-1; i++)
    {
        for (int j=0; j<width-1; j++)
        {


            //average:
            if ((i>0)&&(i<height-1)&&(j>0)&&(j<width-1))//ta tudo fiscando escuro por causa dos cantos?
            {
             for (int x=-1; x<=1; x++)
             {
               for (int y=-1; y<=1; y++)
                {
                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i+x][j+y].rgbtBlue/9);
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (image[i+x][j+y].rgbtGreen/9);
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (image[i+x][j+y].rgbtRed/9);
                }
             }
            }
        }
    }
            //canto superior esquerdo
            for (int i=0; i<1; i++)
            {
                for (int j=0; j<1; j++)
                {
                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/4;  //(image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/3;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/4; //(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/3;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtGreen + (image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/4;   //(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/3;
                }
            }

            //borda de cima
            for (int i=0; i<1; i++)
            {
                for (int j=1; j<width-1; j++)
                {
                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i][j+1].rgbtBlue)/9;  //(image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i][j-1].rgbtBlue)/5;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen +(image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i][j+1].rgbtGreen)/9; //(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i][j-1].rgbtGreen)/5;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed+image[i][j+1].rgbtRed)/9;  //(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i][j-1].rgbtRed)/5;
                }

            }

            //borda da esquerda
            for (int j=0; j<1; j++)
            {
                for (int i=1; i<height-1; i++)
                {
                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j].rgbtBlue)/6;  //(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j].rgbtGreen)/6; //(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j].rgbtRed)/6;   //(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i-1][j].rgbtBlue)/5;
                }
            }
            //canto inferior esquerdo
            for(int j=0; j<1; j++)
            {
                for (int i=height-1; i<height; i++)
                {
                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i][j].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i-1][j].rgbtBlue+image[i][j+1].rgbtBlue)/4;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (image[i][j].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i-1][j].rgbtGreen+image[i][j+1].rgbtGreen)/4;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtBlue + (image[i][j].rgbtRed+image[i-1][j+1].rgbtRed+image[i-1][j].rgbtRed+image[i][j+1].rgbtRed)/4;
                }
            }
            //borda de baixo
            for (int i=height-1; i<height; i++)
            {
                for (int j=1; j<width-1; j++)
                {
                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i][j+1].rgbtBlue)/6;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i][j+1].rgbtGreen)/6;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed+image[i][j+1].rgbtRed)/6;
                }
            }
            //canto superior direito
            for (int i=0; i<1; i++)
            {
                for (int j=width-1; j<width; j++)
                {
                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/4;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/4;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/4;
                }
            }
            //borda da direita
            for (int j=width-1; j<width; j++)
            {
                for (int i=1; i<height-1; i++)
                {
                   newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j].rgbtBlue)/6;
                   newimage[i][j].rgbtGreen = newimage[i][j].rgbtGreen + (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j].rgbtGreen)/6;
                   newimage[i][j].rgbtRed = newimage[i][j].rgbtRed + (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j].rgbtRed)/6;
                }
            }
            //canto inferior direito
            for (int i=height-1; i<height; i++)
            {
                for (int j=width-1; j<width; j++)
                {
                    newimage[i][j].rgbtBlue = newimage[i][j].rgbtBlue + (image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i-1][j].rgbtBlue)/4;
                    newimage[i][j].rgbtGreen = newimage[i][j].rgbtBlue + (image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i-1][j].rgbtGreen)/4;
                    newimage[i][j].rgbtRed = newimage[i][j].rgbtBlue + (image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i-1][j-1].rgbtRed+image[i-1][j].rgbtRed)/4;
                }

            }



    for (int i=0; i<height-1; i++)
    {
        for (int j=0; j<width-1; j++)
            {
                image[i][j].rgbtBlue = newimage[i][j].rgbtBlue;
                image[i][j].rgbtGreen = newimage[i][j].rgbtGreen;
                image[i][j].rgbtRed = newimage[i][j].rgbtRed;
            }
    }
    return;
}












