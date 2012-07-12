/* See LICENSE in dwm source code package for copyright and license details. */
/**/
/* This is the config.h for dwm with icons and colors in font.*/
/**/
/* This file was made by gnusosa (gnusosa@gnusosa.net)*/
/* 8169 8649 6995 DF85 80AD  F778 A145 52AD A100 F1A7 */
/* This file can be distributed under the same license that dwm works with */ 


#include "im-grid.c"
#include "push.c"
#include "X11/XF86keysym.h"
#include "togglefullscreen.c"

/* appearance */
static const char font[] = "-*-stlarch-medium-r-*-*-10-*-*-*-*-*-*-*" "," "-*-termsyn-medium-*-*-*-11-*-*-*-*-*-*-*";

#define NUMCOLORS 21
static const char colors[NUMCOLORS][ColLast][21] = {
    // border     foreground background
    { "#1A1A1A", "#808080", "#020202" },  // 01 - normal
    { "#4C4C4C", "#B3B3B3", "#020202" },  // 02 - selected
    { "#B3354C", "#B3354C", "#020202" },  // 03 - urgent

    { "#1A1A1A", "#1A1A1A", "#020202" },  // 04 - black
    { "#802635", "#802635", "#020202" },  // 05 - red
    { "#608040", "#608040", "#020202" },  // 06 - green
    { "#877C43", "#877C43", "#020202" },  // 07 - yellow
    { "#1C678C", "#1C678C", "#020202" },  // 08 - blue
    { "#684D80", "#684D80", "#020202" },  // 09 - magenta
    { "#000000", "#000000", "#000000" },  // unusable
    { "#337373", "#337373", "#020202" },  // 0B - cyan
    { "#808080", "#808080", "#020202" },  // 0C - light gray
    { "#4C4C4C", "#4C4C4C", "#020202" },  // 0D - gray
    { "#B3354C", "#B3354C", "#020202" },  // 0E - light red
    { "#4BA65A", "#4BA65A", "#020202" },  // 0F - light green
    { "#BF9F5F", "#BF9F5F", "#020202" },  // 10 - light yellow
    { "#3995BF", "#3995BF", "#020202" },  // 11 - light blue
    { "#A64286", "#A64286", "#020202" },  // 12 - light magenta
    { "#6C98A6", "#6C98A6", "#020202" },  // 13 - light cyan
    { "#B3B3B3", "#B3B3B3", "#020202" },  // 14 - white

    { "#802635", "#BF9F5F", "#802635" },  // 15 - warning
};

static const unsigned int borderpx       = 1;                // border pixel of windows
static const unsigned int snap           = 5;                // snap pixel
static const unsigned int systrayspacing = 1;                // space between systray icons
static const Bool showsystray            = False;             // False means no systray
static const Bool showbar                = True;             // False means no bar
static const Bool topbar                 = True;             // False means bottom bar
static Bool useicons                     = True;             // False means use ascii symbols
static const char scratchpadname[]       = "Scratchpad";

/* layout(s) */
static const float mfact      = 0.50;     // factor of master area size [0.05..0.95]
static const Bool resizehints = False;    // True means respect size hints in tiled resizals
static const int nmaster      = 1;        // default number of clients in the master area

static const Layout layouts[] = {
    // icon                                    symbol    arrange function
    { "/home/gnusosa/.dwm/icons/tile.xbm",     "þ",      tile },
    { "/home/gnusosa/.dwm/icons/bstack.xbm",   "ü",      bstack },
    { "/home/gnusosa/.dwm/icons/float.xbm",    "ý",      NULL },     // no layout function means floating behavior
    { "/home/gnusosa/.dwm/icons/monocle.xbm",  "ÿ",      monocle },
    { "/home/gnusosa/.dwm/icons/grid.xbm",     "ú",      imgrid },
};

static const MonocleNumberedIcon monoclenumberedicons[] = {
	{ "/home/gnusosa/.dwm/icons/monocle0.xbm" },
	{ "/home/gnusosa/.dwm/icons/monocle1.xbm" },
	{ "/home/gnusosa/.dwm/icons/monocle2.xbm" },
	{ "/home/gnusosa/.dwm/icons/monocle3.xbm" },
	{ "/home/gnusosa/.dwm/icons/monocle4.xbm" },
	{ "/home/gnusosa/.dwm/icons/monocle5.xbm" },
};

/* tagging */
static const Tag tags[] = {
        // name       layout           mfact    nmaster
        //{ "",        &layouts[3],     -1,      -1 },
        { "",        &layouts[0],   0.65,      -1 },
        { "",        &layouts[3],     -1,      -1 },
        { "",        &layouts[3],     -1,      -1 },
        { "",        &layouts[3],     -1,      -1 },
        { "",        &layouts[4],   0.22,      -1 },
        { "",        &layouts[0],   0.65,      -1 },
        { "",        &layouts[0],   0.65,      -1 },
        { "",        &layouts[3],     -1,      -1 },
        { "",        &layouts[2],     -1,      -1 },
};

/* window rules */
static const Rule rules[] = {
        // class                  instance  title                  tags mask  isfloating  iscentred   monitor
        { "mplayer",             NULL,      NULL,                 0,            True,                   -1 },
	{ "Firefox",  		 NULL,      NULL,       	  1 << 3,       False,        		-1 },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] ={ "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]  = { "urxvtc", NULL };
static const char *scratchpadcmd[] = { "urxvtc", "-title", scratchpadname, "-geometry", "70x9+400+10", NULL };

#include "moveresize.c"
static Key keys[] = {
   // modifier                       key                       function          argument
	/* Here starts the moveresize keys */
	{ MODKEY,                       XK_Down,   moveresize,     {.v = (int []){ 0, 25, 0, 0 }}},
	{ MODKEY,                       XK_Up,     moveresize,     {.v = (int []){ 0, -25, 0, 0 }}},
	{ MODKEY,                       XK_Right,  moveresize,     {.v = (int []){ 25, 0, 0, 0 }}},
	{ MODKEY,                       XK_Left,   moveresize,     {.v = (int []){ -25, 0, 0, 0 }}},
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = (int []){ 0, 0, 0, 25 }}},
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = (int []){ 0, 0, 0, -25 }}},
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = (int []){ 0, 0, 25, 0 }}},
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = (int []){ 0, 0, -25, 0 }}},
	/* Here ends the moveresize keys   */
	/* Here starts the nmaster keys    */
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	/*{ MODKEY,                       XK_x,      setnmaster,     {.i = 2 } },*/
	{ MODKEY,                       XK_Tab,      swapfocus,      {0} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,      pushdown,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      pushup,      {.i = -1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY,                        XK_t,                     setlayout,        {.v = &layouts[0]} },
    { MODKEY,                        XK_b,                     setlayout,        {.v = &layouts[1]} },
    { MODKEY,                        XK_f,                     setlayout,        {.v = &layouts[2]} },
    { MODKEY|ShiftMask,              XK_f,                     togglefullscreen, {0} },
    { MODKEY,                        XK_m,                     setlayout,        {.v = &layouts[3]} },
    { MODKEY,                        XK_g,                     setlayout,        {.v = &layouts[4]} },
    { 0,                             XK_F12,                   togglescratch,    {.v = scratchpadcmd} },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
    /*{ 0,                             XF86XK_Launch1,           spawn,            {.v = screenoffcmd } },
    { 0,                             XF86XK_PowerOff,          spawn,            {.v = shutdowncmd } },
    { 0,                             XF86XK_AudioLowerVolume,  spawn,            {.v = voldowncmd } },
    { 0,                             XF86XK_AudioMute,         spawn,            {.v = voltogglecmd } },
    { 0,                             XF86XK_AudioRaiseVolume,  spawn,            {.v = volupcmd } },
    */
};

#include "tilemovemouse.c"
/* button definitions */
// click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin
static Button buttons[] = {
    // click                event mask      button          function        argument
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkWinTitle,          0,              Button1,        focusstack,     {.i = +1 } },
    { ClkWinTitle,          0,              Button3,        focusstack,     {.i = -1 } },
    { ClkClientWin,         MODKEY,         Button1,        tilemovemouse,  {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    /*{ ClkRootWin,           0,              Button3,        spawn,          {.v = menucmd } },
    { ClkStatusText,        0,              Button1,        spawn,          {.v = calendarcmd } },
    { ClkStatusText,        0,              Button3,        spawn,          {.v = menucmd } },
    */
};

