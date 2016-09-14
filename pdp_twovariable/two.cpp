int two(int l1,int l2,int u1,int u2,int c,int & atwo,int & btwo,bool & ctwo) 
{
	int sum1,sum2;
	sum1 = l1+l2;
	sum2 = u1+u2;
	if(c>=sum1 && c<=sum2)
	{
        ctwo = true;
		atwo = l1;
		btwo = u1;
		if(atwo+u2 < c)
		{
			atwo = c-u2;
		}
		if(btwo+l2 > c)
		{
			btwo = c-l2;
		}
	}
	else
	{
    	ctwo = false;
	}
}
