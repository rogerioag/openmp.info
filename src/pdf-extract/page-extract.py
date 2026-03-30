import PyPDF2 
  
# creating a pdf file object 
pdfFileObj = open('OpenMP-API-Specification-5.0.pdf', 'rb') 
  
# creating a pdf reader object 
pdfReader = PyPDF2.PdfFileReader(pdfFileObj) 

print(pdfReader.isEncrypted)
  
# printing number of pages in pdf file 
print(pdfReader.numPages) 
  
# creating a page object 
pageObj = pdfReader.getPage(110) 

print(pageObj) 

# extracting text from page 
print(pageObj.extractText()) 
  
# closing the pdf file object 
pdfFileObj.close() 