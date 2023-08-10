/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 12;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 12;       /* vert inner gap between windows */
static const unsigned int gappoh    = 12;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 12;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 12;        /* vertical padding of bar */
static const int sidepad            = 12;        /* horizontal padding of bar */
static const char *fonts[]          = { "Hack Nerd Font:pixelsize=12:antialias=true:autohint=true" };
static const char dmenufont[]       = "Hack Nerd Font:pixelsize=12:antialias=true:autohint=true";
static char normfgcolor[]           = "#a89984"; //                                (C7) (Not used anymore, replaced by other norm fg)
static char normbgcolor[]           = "#32302f"; //                                (C0) (Not used anymore, replaced by other norm bg)
static char selfgcolor[]            = "#ebdbb2"; //                                (FG) (Not used anymore, replaced by other sel fg)
static char selbgcolor[]            = "#282828"; //                                (BG) (Not used anymore, replaced by other sel bg)
static char normbordercolor[]       = "#32302f"; // Unfocused window border        (C0)
static char selbordercolor[]        = "#cc241d"; // Selected window border         (C1)
static char statusfg[]              = "#928374"; // Status bar text                (C1)
static char statusbg[]              = "#282828"; // Status bar background          (BG)
static char tagnormfg[]             = "#928374"; // Normal tag text                (C8)
static char tagnormbg[]             = "#282828"; // Normal tag bagground           (BG)
static char tagselfg[]              = "#cc241d"; // Selected tag text              (C1)
static char tagselbg[]              = "#32302f"; // Selected tag background        (C0)
static char infonormfg[]            = "#ebdbb2"; // Normal middle bar text         (FG) (NEVER USED)
static char infonormbg[]            = "#282828"; // Normal middle bar background   (BG)
static char infoselfg[]             = "#282828"; // Selected middle bar text       (BG)
static char infoselbg[]             = "#cc241d"; // Selected middle bar background (C1)
static char borderbar[]             = "#32302f"; // Border around the entire bar   (C0)

static char termcol0[] = "#000000"; /* black   */
static char termcol1[] = "#ff0000"; /* red     */
static char termcol2[] = "#33ff00"; /* green   */
static char termcol3[] = "#ff0099"; /* yellow  */
static char termcol4[] = "#0066ff"; /* blue    */
static char termcol5[] = "#cc00ff"; /* magenta */
static char termcol6[] = "#00ffff"; /* cyan    */
static char termcol7[] = "#d0d0d0"; /* white   */
static char termcol8[]  = "#808080"; /* black   */
static char termcol9[]  = "#ff0000"; /* red     */
static char termcol10[] = "#33ff00"; /* green   */
static char termcol11[] = "#ff0099"; /* yellow  */
static char termcol12[] = "#0066ff"; /* blue    */
static char termcol13[] = "#cc00ff"; /* magenta */
static char termcol14[] = "#00ffff"; /* cyan    */
static char termcol15[] = "#ffffff"; /* white   */
static char termcol16[]= "#282828"; /* background, is set to 16 because it needs to be a number */
static char termcol17[]= "#ebdbb2"; /* foreground, is set to 17 because it needs to be a number */
static char *termcolor[] = {
  termcol0,
  termcol1,
  termcol2,
  termcol3,
  termcol4,
  termcol5,
  termcol6,
  termcol7,
  termcol8,
  termcol9,
  termcol10,
  termcol11,
  termcol12,
  termcol13,
  termcol14,
  termcol15,
  termcol16,
  termcol17,
};

static char *colors[][3] = {
       /*                        fg           bg           border   */
       [SchemeNorm]      = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]       = { selfgcolor,  selbgcolor,  selbordercolor  },
       [SchemeStatus]    = { statusfg,    statusbg,    borderbar       }, // Statusbar right {text,background,not used but cannot be empty}
       [SchemeTagsNorm]  = { tagnormfg,   tagnormbg,   borderbar       }, // Tagbar left unselected {text,background,not used but cannot be empty}
       [SchemeTagsSel]   = { tagselfg,    tagselbg,    borderbar       }, // Tagbar left selected {text,background,not used but cannot be empty}
       [SchemeInfoNorm]  = { infonormfg,  infonormbg,  borderbar       }, // infobar middle  unselected {text,background,not used but cannot be empty}
       [SchemeInfoSel]   = { infoselfg,   infoselbg,   borderbar       }, // infobar middle  selected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor    float x,y,w,h         floatborderpx*/
	{ "Gimp",     NULL,       NULL,       0,            1,           -1,        50,50,500,500,        3 },
	{ "firefox",  NULL,       NULL,       1 << 8,       0,           -1,        50,50,500,500,        3 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "HHH",      grid },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
//	{ MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
//	{ MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_t,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask,              XK_r,      defaultgaps,    {0} },
//	{ MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
//	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
//	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
//	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },
   { MODKEY,                       XK_q,      spawn,          SHCMD("dmenu_shutdown") },
   { 0,            XF86XK_MonBrightnessDown,  spawn,          SHCMD("br dec 2") },
   { 0,            XF86XK_MonBrightnessUp,    spawn,          SHCMD("br inc 2") },
   { 0,            XF86XK_AudioLowerVolume,   spawn,          SHCMD("vl dec 0.05") },
   { 0,            XF86XK_AudioRaiseVolume,   spawn,          SHCMD("vl inc 0.05") },
   { 0,            XF86XK_AudioMute,          spawn,          SHCMD("vl toggle_mute") },
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
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} }, // Left click
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} }, // Middle click
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} }, // Right click
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} }, // Scrollup 
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} }, // Scrooldown
   { ClkStatusText,        ShiftMask,      Button1,        sigstatusbar,   {.i = 6} }, // Shift + Left click
   { ClkStatusText,        ShiftMask,      Button2,        sigstatusbar,   {.i = 7} }, // Shift + Middle click
   { ClkStatusText,        ShiftMask,      Button3,        sigstatusbar,   {.i = 8} }, // Shift + Right click
   { ClkStatusText,        ShiftMask,      Button4,        sigstatusbar,   {.i = 9} }, // Shift + Scrollup
   { ClkStatusText,        ShiftMask,      Button5,        sigstatusbar,   {.i = 10} }, // Shift + Scrooldown
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
