int gcd(int a,int b)
{
	if(b%a == 0)
	{
		return a;
	}
	gcd(b%a,a);
}

bool ifint(float a)
{
	int b = static_cast<int>(a);

	if(b-a == 0)
	{
		return true;
	}
	return false;
}

bool ifsol(int a,int b,int c)
{
	if(a>b)
	{
		int temp;
		temp = b;
		b = a;
		a = temp;
	}
	int g = gcd(a,b);
	if(c%g == 0)
	{
		return true;
	}
	return false;
}

void solution(int a,int b,int c,int &x0, int &y0)
{
	int u,v,x,y;
	
	bool check;
	float d;
	if(ifsol(a,b,c))
	{
		if(a+b!=0)
		{
			d = (float)c/((float)a+(float)b);
			u = c;
			v = c;
			while(!ifint(d))
			{
				u = u+a;
				d = (float)u/((float)a+(float)b);
				if(!ifint(d))
				{
					v = v-a;
        	       			d = (float)v/((float)a+(float)b);
				}
			}
			x = (u-c)/a;
			y = (c-v)/a;
			if(x == y)
			{
				x0 = d+y;
                y0 = d;
			}
			else
			{
                x0 = d-x;
                y0 = d;
            }	
		}
		else
		{
			if(c!=0)
			{
                x0 = c/a;
                y0 = d;
			}
			else
			{
                x0 = 0;
                y0 = 0;
			}
		}
	}
}
