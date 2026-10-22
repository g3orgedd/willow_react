/* ClariSoft stores a typeface name in Font/Face. Font/Family is the separate
   GDI family classification (Roman, Swiss, Modern, ...), not a typeface name. */
const CLARISOFT_DEFAULT_TEXT_FONT_FACE = "Arial";
const CLARISOFT_DEFAULT_TEXT_PITCH = 13;

function getEffectiveTextFontFamily(field) {
  const face = String(field?.text?.face ?? "").trim();
  return face || CLARISOFT_DEFAULT_TEXT_FONT_FACE;
}

function getTextCanvasFontFamily(field) {
  // Quote the complete Windows face name, including embedded commas/quotes.
  return `${JSON.stringify(getEffectiveTextFontFamily(field))}, sans-serif`;
}

function getTextCanvasFontStyle(field) {
  const parts = [];
  if (field?.text?.italic) parts.push("italic");
  if (field?.text?.bold) parts.push("bold");
  return parts.join(" ") || "normal";
}

function getTextVerticalMagnification(field) {
  const value = Number(field?.text?.yMag);
  return Number.isFinite(value) && value > 0 ? value / 100 : 1;
}
