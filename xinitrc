xrdb -merge ~/.Xresources
xset +fp /usr/share/fonts/local
xset fp rehash

xscreensaver &

urxvtd -q -o -f &


exec dbus-launch /home/gnusosa/.dwm/dwm-start

