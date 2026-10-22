"""Explicit object-model inputs for the installed native serializer oracle."""
from pathlib import Path
import json
HERE = Path(__file__).resolve().parent
cases = []
def field(type=0, subtype=0, properties=None, objects=None, name='Field00'):
    return dict(type=type, subtype=subtype, name=name, properties=properties or {}, objects=objects or [])
def data(type=0, index=0, static=True, parse=False, **properties):
    return dict(type=type, index=index, static=static, parse=parse, properties=properties)
def case(name, *fields): cases.append(dict(name=name, fields=fields))

for ft in range(3): case(f'field-family-{ft}-defaults',field(ft))
for name, value in {'FieldDisplayed':0,'FieldXPos':-100,'FieldYPos':123,'FieldWidth':456,
                    'FieldHeight':789,'FieldLine':1,'FieldOrientation':90,'OverrideThis':1,
                    'FieldInverse':1,'FieldMirror':1,'FieldRenderMode':1,
                    'CalculatedData':'A\x01B\tC\nD\rE\x1fF<&>',
                    'FieldLogged':'custom-log','ClearStyleFieldType':'FixedText'}.items():
    case('common-'+name,field(properties={name:value}))
for i, value in enumerate(['',None,'Not Logged']): case(f'logged-{i}',field(properties={'FieldLogged':value}))
for name, value in {'FontName':'OCRB','FontFamily':16,'FontPitch':8,'FontXMag':125,'FontYMag':150,
                    'FontTrueTypeSize':2,'BoldText':1,'BoldWeight':700,'ItalicText':1,'DoubleSpace':1,
                    'BlockWidth':200,'BlockHeight':300,'BlockMaximumLines':2,'BlockMinimumFontSize':6,
                    'BlockJustification':2,'BlockHyphenation':1,'FontPitchResolution':2}.items():
    case('text-'+name,field(properties={name:value}))
case('block-default',field(subtype=1))
case('block-complete',field(subtype=1,properties={'BlockWidth':2000,'BlockHeight':1200,'BlockMaximumLines':3,'BlockMinimumFontSize':6,'BlockJustification':2,'BlockHyphenation':1}))
for subtype in range(27): case(f'barcode-subtype-{subtype:02d}',field(1,subtype))
for name, value in {'Magnification':1250,'Height':1200,'HRDisplayed':1,'HRAbove':1,'HRFontName':'Arial',
                    'HRFontPitch':8,'HRFontXMag':125,'HRFontYMag':150,'HRFontTTSize':2,
                    'CheckDigit':1,'QuietMargins':0,'XOffset':15,'BarcodePrinting':1,
                    'HRPrintCheckDigit':0,'BarcodeMagnificationRoundingFactor':25}.items():
    case('barcode-'+name,field(1,properties={name:value}))
case('barcode-itf-extensions',field(1,properties={'ThickToThinRatio':300,'BearerBars':1,'BearerBox':1,'HGauge':20}))
case('barcode-datamatrix-extensions',field(1,15,properties={'ECCType':3,'ModuleSize':50,'SymbolSize':7,'ClearStyleFieldType':'Barcode'}))
case('barcode-qr-extensions',field(1,18,properties={'ModuleSize':50,'QRVersion':3,'QRErrLevel':2,'QRMirror':1,'ClearStyleFieldType':'Barcode'}))
case('barcode-pdf417-extensions',field(1,16,properties={'ModuleSize':50,'RowHeight':4,'Columns':5,'MaximumRows':6,'ErrorCorrection':2,'PDF417Type':1,'PDF417Encoding':1}))
for subtype in range(4): case(f'graphic-subtype-{subtype}',field(2,subtype))
for shape in range(8): case(f'graphic-shape-{shape}',field(2,0,properties={'PrimitiveShape':shape,'LineWidth':10}))
case('graphic-static-options',field(2,1,properties={'GraphicWidth':128,'GraphicHeight':64,'MaintainAspectRatio':0,'ResizeFrame':1,'LogoReferencePrinter':1}))
for type in range(9):
    case(f'data-branch-{type}',field(objects=[data(type, DefaultData='Sample<&>',ClearStyleDataType=type)]))
for index, static, parse in [(0,True,False),(1,True,False),(2,False,True),(3,False,False)]:
    case(f'data-flags-{index}',field(objects=[data(index=index,static=static,parse=parse,DefaultData='value')]))
for name, value in {'FixedLength':1,'FixedLengthPadCharacter':48,'FixedLengthPadMode':1,
                    'Locale':'RU-RU','Calendar':2,'Encryption':'Example.Component',
                    'MaximumCharacters':31,'DefaultData':'Default<&>','Reference':'source-key'}.items():
    case('object-'+name,field(objects=[data(**{name:value})]))
case('object-fixed-padding',field(objects=[data(FixedLength=1,FixedLengthPadCharacter=48,FixedLengthPadMode=1)]))
case('source-field',field(objects=[data(1,SourceFieldName='SRC',StartCharacter=2,NumberOfCharacters=5)]))
case('source-data',field(objects=[data(2,ConnStr='example-connection-string',SourceSQL='SELECT code\nFROM sample',ClearStyleDataType=6)]))
case('user-text',field(properties={'ClearStyleFieldType':'FixedText'},objects=[data(3,static=False,DefaultData='DEFAULT',VariableTextPrompt='Enter code',VariableTextInputMask='NNNN',VariableTextUserEnteredData='1234',VariableTextPromptAtCoder=1,VariableTextResetOnSelect=1)]))
case('offset-date',field(properties={'ClearStyleFieldType':'OffsetDateText'},objects=[data(4,static=False,parse=True,ClearStyleDataType=3,DefaultData="dd'/'MM'/'yyyy",OffsetDateSourceName='ShelfLife')]))
case('counter',field(properties={'ClearStyleFieldType':'CounterText'},objects=[data(5,static=False,ClearStyleDataType=4,DefaultData='0001',PrintsPerCount=3,ResetOnSelect=1,Rollover=0)]))
case('data-collection-order',field(objects=[data(index=9,DefaultData='first'),data(index=1,DefaultData='second'),data(index=5,DefaultData='third')]))
case('field-collection-order',field(name='Z'),field(name='A'),field(name='M'))
case('duplicate-field-name',field(name='SAME',properties={'FieldXPos':100}),field(name='SAME',properties={'FieldXPos':200}))
case('duplicate-data-index',field(objects=[data(index=0,DefaultData='first'),data(index=0,DefaultData='second')]))
for name,obj in [
    ('fixed',data(ClearStyleDataType=0,DefaultData='Hello<&>')),
    ('time',data(static=False,parse=True,ClearStyleDataType=1,DefaultData="HH':'mm")),
    ('date',data(static=False,parse=True,ClearStyleDataType=2,DefaultData="dd'/'MM'/'yyyy")),
    ('user',data(3,static=False,ClearStyleDataType=0,DefaultData='DEFAULT',VariableTextUserEnteredData='OPERATOR')),
    ('fixed-pad',data(static=False,ClearStyleDataType=0,DefaultData='abc',MaximumCharacters=6,FixedLength=1,FixedLengthPadCharacter=48,FixedLengthPadMode=1)),
]:
    case('runtime-'+name,field(objects=[obj]));cases[-1]['resolve']=True
counter=data(5,static=False,parse=True,ClearStyleDataType=4,PrintsPerCount=3)
counter['subCounters']=[dict(significance=0,alphaNumeric=False,leadCharacter=48,order=0,properties={'Used':1,'NumberOfCharacters':4,'LeadingCharacters':1,'StartValue':'0','EndValue':'9999','CurrentValue':'42','StepSize':1})]
case('counter-subcounter',field(objects=[counter]))
case('runtime-counter',field(objects=[counter]));cases[-1]['resolve']=True
case('with-native-clst',field(properties={'ClearStyleFieldType':'FixedText','CalculatedData':'Hello'},objects=[data(DefaultData='Hello')]));cases[-1]['generateClSt']=True
case('with-native-clst-empty');cases[-1]['generateClSt']=True
case('runtime-source-field',field(name='SOURCE',objects=[data(DefaultData='ABCDE')]),field(name='TARGET',objects=[data(1,static=False,ClearStyleDataType=5,SourceFieldName='SOURCE',StartCharacter=1,NumberOfCharacters=3)]));cases[-1]['resolve']=True
case('native-time-recipe',field(properties={'ClearStyleFieldType':'TimeText','FieldLine':1,'FontPitch':8},objects=[data(static=False,parse=True,ClearStyleDataType=1,DefaultData="HH':'mm") ]));cases[-1]['resolve']=True;cases[-1]['generateClSt']=True
case('native-dm-template',field(1,15,properties={'ClearStyleFieldType':'Barcode','ModuleSize':50,'SymbolSize':6,'QuietMargins':0,'FieldWidth':1100,'FieldHeight':1100,'Height':1100,'CalculatedData':'~1010123456789012821ABC123'},objects=[data(DefaultData='~101'),data(index=1,DefaultData='01234567890128'),data(index=2,DefaultData='21'),data(index=3,DefaultData='ABC123')]));cases[-1]['generateClSt']=True
for c in cases:
    if c['name'] in ['text-BlockWidth','text-BlockMaximumLines','text-BlockMinimumFontSize','object-FixedLengthPadCharacter','object-FixedLengthPadMode']:
        c['expectedError']='E_ACCESSDENIED'
(HERE/'oracle-cases.json').write_text(json.dumps(cases,ensure_ascii=True,indent=2),encoding='utf8')
print(json.dumps({'caseCount':len(cases)}))
