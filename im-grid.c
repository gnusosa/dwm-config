static const char wmname[] = "Skype";

/* layout's mfact is buddy list width as ww % */
void
imgrid(Monitor *m) {
	unsigned int n, cols, rows, cn, rn, i, cx, cy, cw, ch;
  int wx; /* buddy list width and grid's wx */
  int ww; /* grid's ww */
	Client *c;
  Client *bl = NULL; /* buddy list */

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++) {
    if(strstr(c->name, wmname)) {
      bl = c;
    }
  }
	if(n == 0)
		return;

  /* buddy list */
  if(bl) {
    wx = m->mfacts[m->curtag] * m->ww;
    ww = m->ww - wx;
    resize(bl, m->wx, m->wy, wx - 2 * bl->bw, m->wh - 2 * bl->bw, False);
    if(--n == 0)
      return;
  } else {
    wx = m->wx;
    ww = m->ww;
  }

	/* grid dimensions */
	for(cols = 0; cols <= n/2; cols++)
		if(cols*cols >= n)
			break;
	if(n == 5) /* set layout against the general calculation: not 1:2:2, but 2:3 */
		cols = 2;
	rows = n/cols;

	/* window geometries */
	cw = cols ? ww / cols : ww;
	cn = 0; /* current column number */
	rn = 0; /* current row number */
	for(i = 0, c = nexttiled(m->clients); c; i++, c = nexttiled(c->next)) {
    if(c == bl) {
      --i;
      continue;
    }
		if(i/rows + 1 > cols - n%cols)
			rows = n/cols + 1;
		ch = rows ? m->wh / rows : m->wh;
		cx = wx + cn*cw;
		cy = m->wy + rn*ch;
		resize(c, cx, cy, cw - 2 * c->bw, ch - 2 * c->bw, False);
		rn++;
		if(rn >= rows) {
			rn = 0;
			cn++;
		}
	}
}
