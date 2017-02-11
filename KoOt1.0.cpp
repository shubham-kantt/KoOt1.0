
	// Program to Encrypt and Decrypt Data

	#include<stdio.h>
	#include<string.h>
	
	#define SIZE 500       // Max No Character which can be stored as a input
	#define KEY_SIZE 31    // Max Size of Key is ( KEY_SIZE - 1 )  ,  because 1 byte is for '\0'

	void encryptionDecryptionOfText( char* , char* , int ) ;    
	
	int KeyLen, TextLen ;  

	int main()
	{
		int Choice ;
		char PlainText[SIZE] , EncryptedText[SIZE] ; 
		char Key[KEY_SIZE] , SecretKey1[] = "!$*(gi%~.,&fuam4^<[}\3em8os#*-" , SecretKey2[] = "gR3$7(~G `.<_&@!\%1*9Azf2-+:;\"P" ;   

		                  // Secret Key is arbitrary , Secret Key Size : 30 Char
		
		printf ( "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Welcome to KoOt\n\n\n\n\a" ) ;
		printf ( " Please Select one of the following Options -:\n\n" ) ;
		printf ( " * Press 1 for Encryption\n * Press 2 for Decryption\n * Press 3 for Exit\n\n" ) ;
		scanf ( "%d" , &Choice ) ;
		fflush (stdin) ;
		
		while ( Choice >= 4 || Choice < 1 )         // IF choice is wrong , program will ask again
		{
			  printf ( "Something went wrong\n" ) ;
			  printf ( "Please Enter the Valid Choice\n" ) ;
			  printf ( " * Press 1 for Encryption\n * Press 2 for Decryption\n * Press 3 for Exit\n\n" ) ;
			  scanf ( "%d" , &Choice ) ;
			  fflush ( stdin ) ;
		}
		
		switch ( Choice )
//This case : Encryption		
		{   case 1: printf ( "\n Enter the Text to be Encrypted\n" ) ;         // Entering PlainText
			        gets ( PlainText ) ;			
			        puts ( "\n Enter Password : " ) ;           // Entering password for encryption
			        gets ( Key ) ;
			    
			        KeyLen = strlen ( Key ) ;
			        TextLen = strlen ( PlainText );

                    for ( int i=0 ; i < KeyLen ; i++ )             // Or function on user key with our secret key
	                {  
	                	if ( (65 <= Key[i])  && (Key[i] <= 90) )
                           Key[i] = Key[i] | SecretKey2[i % 30] ;
	                   
	                    else
	                   	    Key[i] = Key[i] | SecretKey1[i % 30] ;
					} 

		      	    encryptionDecryptionOfText ( PlainText , Key , 0 ) ;
			        break ;

// This case : Decryption		
            case 2: FILE *Decryption ;                           // "Decryption" is pointing to Encrypted.txt file in which encrypted data is saved after encryption
			        Decryption = fopen ( "Encrypted.txt" , "rb" ) ;
			
     			    for ( int i=0 ; !feof(Decryption) ; i++ )      // Inputing encrypted data
	    		    {   fscanf ( Decryption , "%c" , &EncryptedText[i] ) ;
                        TextLen++ ;
	     		       // fgetc ( Decryption ) ;     // ignoring "\" in Encrypted.txt file
	       		    }
			
			        fclose(Decryption);

			        printf ( "\n\n We got your Encrypted Data.\n\n" ) ;
	        
	                printf(" Enter your Password : ");  
			        gets(Key);
			        KeyLen = strlen ( Key ) ;

			       for ( int i=0 ; i < KeyLen ; i++ )             // Or function on user key with our secret key
	               {  
	                	if ( (65 <= Key[i])  && (Key[i] <= 90) )
                           Key[i] = Key[i] | SecretKey2[i % 30] ;
	                   
	                    else
	                   	    Key[i] = Key[i] | SecretKey1[i % 30] ;
				   } 
			
			        encryptionDecryptionOfText ( EncryptedText , Key , 1 ) ;
	                break ;
//This case : Exit		
            case 3: return(1) ;
			        break ;
		}
	}

// To XOR characters in text array with characters in Key array  ; for encryption mode=0 ; for decoding mode=1
		void encryptionDecryptionOfText ( char *text , char *Key , int mode )     // using same function for Encryption and Decryption 
	{	
	    if ( mode == 0 )   // Mode '0' means Encryption
	    {  for ( int j=0 , i=0 ; j < KeyLen ; j++ )          // XORing whole plaintext with 1st char of key then with 2nd char , so on 
	       {   while ( i < TextLen )
		       {   text[i] = text[i] ^ Key[j] ;
	    	       i++;
	           }

	           i=0 ;
	       }    
	        
	       FILE *Encryption = fopen ( "Encrypted.txt", "wb" ) ;    // "Encryption" is pointing file in which encrypted data will be stored 
           printf ( "\n----------------------------------------------------------") ;	 
	       printf ( "\n\n Encrypted Data : " ) ;

	       for ( int i=0 ; i < TextLen ; i++ )     
           {   printf ( "%c" , text[i] ) ;           // Printing encrypted data in terminal , like "@#$@$@#"
	           fprintf ( Encryption , "%c" , text[i] ) ;    // Adding Encrypted data in the file , like 1\23\122\34\45\56    ;   firstChar\SecondChar\ so on
	       }
	       printf ( "\n\n----------------------------------------------------------") ;
		   fclose(Encryption);
		   printf ( "\n\n $$$ We saved your Encrypted Data into file Encrypted.txt in the same Directory in which you have our program.\n\n" ) ;
		   printf ( " $$$ If you want to share your data then share this Encrypted.txt with our program .\n\n\n\n\n" ) ;
		}
	    
	    else if ( mode == 1 )  // mode 1 means decryption
	    {   
	    	for ( int j = 0 , i = 0 ; j < KeyLen ; j++ )   // Decoding
	        {   while ( i < TextLen )
		        {     text[i] = text[i] ^ Key[j] ;
	    	          i++ ;
	            }

	            i=0 ;
	        }
	        
	        printf ( "\n----------------------------------------------------------") ;
	        printf ( "\n\n Decrypted Data : " ) ;
	        for ( int i=0 ; i < (TextLen - 1) ; i++ )
	            printf ( "%c" , text[i] ) ;
	        
			printf ( "\n\n----------------------------------------------------------") ;
	        printf( "\n\n We hope that you liked our program !\a\a\n\n" ) ;
	    }
    }


 
