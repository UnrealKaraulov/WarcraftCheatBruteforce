#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

using namespace std;

#include "IniWriter.h"

char alphabet[ ] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ2";
int alphabetSize = sizeof( alphabet ) -1;

int GameDll = 0;

typedef BOOL( __thiscall *sub_6F7B0DA0 )( const char * addr );
sub_6F7B0DA0 sub_6F7B0DA0my = 0;
CIniWriter logfile = CIniWriter( ".\\OutCheats.ini" );




void TestBrute( string a )
{
	if ( sub_6F7B0DA0my( a.c_str( ) ) )
	{
		logfile.WriteInteger( "Cheats", a.c_str( ), 0 );
	}
}
int timer = 10000;
int id = 0;
vector<string> outlistword;
char buffer[ 512 ];
void ProcessBruteStr( string content )
{
	TestBrute( content );
	TestBrute( content + " " + to_string( 200 ) );

}

void ProcessSuffix(  )
{
	char buffer[ 512 ];

	ifstream file( "BruteForce.txt" );
	string content;

	while ( file >> content )
	{
		timer--;
		id++;

		if ( id >= INT_MAX )
		{
			id = 0;
		}

		if ( timer <= 0 )
		{
			timer = 10000;
			logfile.WriteInteger( "GENERAL", "ID", id );
		}

		//memset( &buffer[ 0 ], 0, 512 );
		//CopyMemory( &buffer[ 0 ], &content.c_str( )[ 0 ], strlen( content.c_str( ) ) );
		ProcessBruteStr( content );
	}
}








void WordGenLVL4( string content1, string content2, string content3, string content4 )
{

	ProcessBruteStr( content1 );

	ProcessBruteStr( content1 + content2 );

	ProcessBruteStr( content2 + content1 );

	ProcessBruteStr( content1 + content2 + content3 );

	ProcessBruteStr( content1 + content3 + content2 );

	ProcessBruteStr( content2 + content3 + content1 );

	ProcessBruteStr( content2 + content1 + content3 );

	ProcessBruteStr( content3 + content2 + content1 );

	ProcessBruteStr( content3 + content1 + content2 );

	ProcessBruteStr( content1 + content2 + content3 + content4 );

	ProcessBruteStr( content1 + content2 + content4 + content3 );

	ProcessBruteStr( content1 + content3 + content4 + content2 );

	ProcessBruteStr( content1 + content3 + content2 + content4 );

	ProcessBruteStr( content2 + content3 + content4 + content1 );

	ProcessBruteStr( content2 + content3 + content1 + content4 );

	ProcessBruteStr( content2 + content1 + content4 + content3 );

	ProcessBruteStr( content2 + content1 + content3 + content4 );


	ProcessBruteStr( content3 + content2 + content4 + content1 );

	ProcessBruteStr( content3 + content2 + content1 + content4 );

	ProcessBruteStr( content3 + content1 + content4 + content2 );

	ProcessBruteStr( content3 + content1 + content2 + content4 );


	ProcessBruteStr( content4 + content3 + content2 + content1 );

	ProcessBruteStr( content4 + content3 + content1 + content2 );

	ProcessBruteStr( content4 + content1 + content2 + content3 );

	ProcessBruteStr( content4 + content1 + content3 + content2 );

}


void WordGenLVL3( string content1, string content2, string content3 )
{
	vector<string> temp4vector;

	ifstream file4( "wordgen4.txt" );

	string content4;


	while ( file4 >> content4 )
	{
		temp4vector.push_back( content4 );

	}

	file4.close( );

	for each ( string content4 in temp4vector )
	{
		WordGenLVL4( content1, content2, content3, content4 );
	}

	temp4vector.clear( );
}



void WordGenLVL2( string content1, string content2 )
{
	vector<string> temp3vector;

	ifstream file3( "wordgen3.txt" );

	string content3;


	while ( file3 >> content3 )
	{
		temp3vector.push_back( content3 );

	}

	file3.close( );

	for each ( string content3 in temp3vector )
	{
		WordGenLVL3( content1, content2, content3 );
	}

	temp3vector.clear( );
}


void WordGenLVL1( string content1 )
{

	vector<string> temp2vector;

	ifstream file2( "wordgen2.txt" );

	string content2;


	while ( file2 >> content2 )
	{
		temp2vector.push_back( content2 );

	}

	file2.close( );

	for each ( string content2 in temp2vector )
	{
		WordGenLVL2( content1, content2);
	}

	temp2vector.clear( );

}

void WordGen( )
{
	logfile.WriteString( "GENERAL", "CURRENT1CONTENT", "WordGen" );
	vector<string> temp1vector;

	ifstream file1( "wordgen.txt" );
	
	string content1;
	

	while ( file1 >> content1 )
	{
		temp1vector.push_back( content1 );
		
	}

	file1.close( );

	logfile.WriteString( "GENERAL", "CURRENT1CONTENT", "file1" );
	for ( UINT i = 0; i < temp1vector.size( ); i++ )
	{
		logfile.WriteString( "GENERAL", "CURRENT1CONTENT", temp1vector[ i ].c_str( ) );
		for ( UINT x = 0; x < temp1vector.size( ); x++ )
		{
			logfile.WriteString( "GENERAL", "CURRENT2CONTENT", temp1vector[ x ].c_str( ) );
			for ( UINT z = 0; z < temp1vector.size( ); z++ )
			{
				WordGenLVL4( temp1vector[ i ], temp1vector[ x ], temp1vector[ z ], temp1vector[ i ] );
				WordGenLVL4( temp1vector[ i ], temp1vector[ x ], temp1vector[ z ], temp1vector[ x ] );
				WordGenLVL4( temp1vector[ i ], temp1vector[ x ], temp1vector[ z ], temp1vector[ z ] );
				WordGenLVL4( temp1vector[ i ], temp1vector[ x ], temp1vector[ i ], temp1vector[ i ] );
				WordGenLVL4( temp1vector[ i ], temp1vector[ x ], temp1vector[ x ], temp1vector[ x ] );

			}
		}
	}



	temp1vector.clear( );

	MessageBox( 0, "AllOkay", "OK", 0 );

	std::ofstream output_file( ".\\outdata.txt" );
	std::ostream_iterator<std::string> output_iterator( output_file, "\n" );
	std::copy( outlistword.begin( ), outlistword.end( ), output_iterator );
}

void Brute1( )
{

	ifstream file2( "Suffix1.txt" );
	string content2;
	

	while ( file2 >> content2 )
	{
		
	//	ProcessSuffix( content2 );
		MessageBox( 0, "0", "0", 0 );
	}
	MessageBox( 0, "1OK", "1OK", 0 );
}



void bruteImpl( char* str, unsigned char index, unsigned char maxDepth )
{
	for ( int i = 0; i < alphabetSize; ++i )
	{
		str[ index ] = alphabet[ i ];

		if ( index == maxDepth - 1 )
		{
			TestBrute( str );
		}
		else
		{
			bruteImpl( str, index + 1, maxDepth );
		}
	}
}

void bruteSequential( unsigned char maxLen )
{
	char * buf = new char[ maxLen + 1 ];

	for ( unsigned char i = 1; i <= maxLen; ++i )
	{
		buf[ i ] = '\0';
		bruteImpl( buf, 0, i );
		logfile.WriteInteger( "GENERAL", "ID", i );
	}

	delete[ ] buf;
}

void SetTlsForMe( )
{
#ifdef BOTDEBUG
	PrintDebugInfo( "Set thread access" );
#endif

	UINT32 Data = *( UINT32 * ) ( GameDll + 0xACEB4C );
	UINT32 TlsIndex = *( UINT32 * ) ( GameDll + 0xAB7BF4 );
	if ( TlsIndex )
	{
		UINT32 v5 = **( UINT32 ** ) ( *( UINT32 * ) ( *( UINT32 * ) ( GameDll + 0xACEB5C ) + 4 * Data ) + 44 );
		if ( !v5 || !( *( LPVOID * ) ( v5 + 520 ) ) )
		{
			Sleep( 1000 );
			SetTlsForMe( );
			return;
		}
		TlsSetValue( TlsIndex, *( LPVOID * ) ( v5 + 520 ) );
	}
	else
	{
		Sleep( 1000 );
		SetTlsForMe( );
		return;
	}
}

DWORD WINAPI StartBruteForce( void * )
{
	Sleep( 1000 );
	SetTlsForMe( );
	logfile.WriteString( "GENERAL", "CURRENT1CONTENT", "SETTLS" );
	//WordGen( );
	//MessageBox( 0, "END", "END", 0 );
	ProcessSuffix( );
	//bruteSequential( 50 );
	MessageBox( 0, "END", "END", 0 );
	return 0;
}

BOOL WINAPI DllMain( HINSTANCE hDLL, UINT reason, LPVOID reserved )
{
	if ( reason == DLL_PROCESS_ATTACH )
	{
		DisableThreadLibraryCalls( hDLL );
		GameDll = ( int ) GetModuleHandle( "Game.dll" );
		sub_6F7B0DA0my = ( sub_6F7B0DA0 ) ( GameDll + 0x7B0DA0 );
		CreateThread( 0, 0, StartBruteForce, 0, 0, 0 );
	}
	return TRUE;
}

