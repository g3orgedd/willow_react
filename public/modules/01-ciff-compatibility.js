// ClSt is generated from the document. There are no printer-specific tokens.
function isUsableClStVersionInfo(value) {
  return typeof isValidClStVersionInfoSyntax === "function" && isValidClStVersionInfoSyntax(value);
}

function resolveClStVersionInfo(documentMetadata = {}) {
  if (typeof generateClStVersionInfo !== "function") throw new Error("ClStVersionInfo engine is not loaded.");
  const template = documentMetadata.template ?? { dateOffsets: [], subImages: [{ fields: [] }] };
  return generateClStVersionInfo(template, documentMetadata.now ?? new Date(), documentMetadata.options ?? {});
}

var CIFF_COMPATIBILITY_READY = true;
