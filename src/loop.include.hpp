app.pauser.reset_pause();

app.react_to_buttons();

app.display->draw_digits();

app.blinker->toggle_blinking();

debugger.show_debug_messages(app);

app.pauser.pause();
