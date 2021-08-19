int total_handlers = 0;
typedef struct
{
    int ID;
    UINT message;
    void(*handler)();
} event;

event null_event = { 0 };
event events[1];

LRESULT CALLBACK handle_all_events(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < total_handlers; i++)
	{
		if (&events[i] != NULL)
		{
			if (events[i].ID == wParam && events[i].message == message)
			{
				events[i].handler();
				return 0;
			}
		}
	}
	if(message == WM_DESTROY) PostQuitMessage(0);
	return DefWindowProc(hwnd, message, wParam, lParam);
}

BOOL add_handler(int ID, UINT message, void *handler())
{
	for (int i = 0; i < total_handlers; i++)
	{
		if (events[i].ID == ID && events[i].message == message)
		{
		    return FALSE;
		}
	}
	events[total_handlers].ID = ID;
	events[total_handlers].handler = handler;
	events[total_handlers].message = message;
	total_handlers++;
	return TRUE;
}

BOOL del_handler(int ID, UINT message)
{
	BOOL FOUND = FALSE;
	for (int i = 0; i < total_handlers; i++)
	{
		if(events[i].ID == ID && events[i].message == message)
		{
			events[i] = null_event;
			FOUND = TRUE;
			break;
		}
	} 	
	return FOUND;
}
