void add(void)
{
	int top;
	int bottom;

	if(gs_length < 2)
	{
		/*need at least 2 items to add together*/
		return;
	}

	top = pop();
	bottom = pop();
	push(top + bottom);
	gs_length--;
}

void nop(void)
{
	/*does nothing*/
}

void sub()
{
	int top;
	int bottom;

	if (gs_length < 2)
	{
		/*need at least two items to perform subtraction*/
		return;
	}

	top = pop();
	bottom = pop();
	push(bottom - top);
	gs_length--;
}


void div(void)
{
	int top;
	int bottom;

	if (gs_length < 2)
	{
		/*needs at least two items for division*/
		return;
	}

	top = pop();
	if (top == 0)
	{
		/*division by zero error*/
		return;
	}
	bottom = pop();
	push(bottom / top);
	gs_length--;
}



void mul()
{

}
