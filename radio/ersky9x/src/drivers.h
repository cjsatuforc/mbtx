#ifndef drivers_h
#define drivers_h



//struct t_fifo32
//{
//	uint8_t fifo[32] ;
//	uint32_t in ;
//	uint32_t out ;
//	volatile uint32_t count ;
//} ;

struct t_16bit_fifo32
{
	uint16_t fifo[32] ;
	uint32_t in ;
	uint32_t out ;
	volatile uint32_t count ;
} ;

struct t_serial_tx
{
	uint8_t *buffer ;
	uint16_t size ;
	volatile uint16_t ready ;
} ;

struct t_fifo64
{
	uint8_t fifo[64] ;
	uint32_t in ;
	uint32_t out ;
} ;

// Options in CaptureMode
#define CAP_PPM				0
#define CAP_SERIAL		1
#define CAP_COM1			2

extern uint8_t CaptureMode ;

//extern void put_fifo32( struct t_fifo32 *pfifo, uint8_t byte ) ;
//extern int32_t get_fifo32( struct t_fifo32 *pfifo ) ;
extern void put_fifo64( struct t_fifo64 *pfifo, uint8_t byte ) ;
extern int32_t get_fifo64( struct t_fifo64 *pfifo ) ;
extern struct t_serial_tx Bt_tx ;
extern uint32_t txPdcBt( struct t_serial_tx *data ) ;
extern uint32_t txPdcCom2( struct t_serial_tx *data ) ;
extern void end_bt_tx_interrupt() ;

extern struct t_fifo64 Sbus_fifo ;
extern struct t_fifo64 CaptureRx_fifo ;

extern uint16_t Scc_baudrate ;				// 0 for 125000, 1 for 115200

#ifdef REVX
extern int32_t getJetiWord( void ) ;
extern volatile uint16_t Analog_values[] ;
#else
extern volatile uint16_t Analog_values[] ;
#endif
extern uint16_t Temperature ;		// Raw temp reading
extern uint16_t Max_temperature ;


extern volatile uint32_t Spi_complete ;

#ifdef PCB9XT
extern uint16_t rxTelemetry( void ) ;
extern void init_software_remote( void ) ;
#endif

#ifdef PCBX9D
extern void x9dConsoleInit( void ) ;
extern uint16_t rxTelemetry( void ) ;
extern void USART6_Sbus_configure( void ) ;
extern void stop_USART6_Sbus( void ) ;
#endif

extern uint16_t DsmRxTimeout ;
extern uint16_t WatchdogTimeout ;

extern void putEvent( register uint8_t evt) ;
extern void UART_Configure( uint32_t baudrate, uint32_t masterClock) ;
extern void UART2_Configure( uint32_t baudrate, uint32_t masterClock) ;
extern void UART2_9dataOdd1stop( void ) ;
extern void UART2_timeout_enable( void ) ;
extern void UART2_timeout_disable( void ) ;
extern void UART_Sbus_configure( uint32_t masterClock ) ;
extern void UART_Sbus57600_configure( uint32_t masterClock ) ;
extern void jetiSendWord( uint16_t word ) ;
extern void init_software_com1(uint32_t baudrate, uint32_t invert) ;
//extern void UART_Stop( void ) ;
//extern void Bt_UART_Stop( void ) ;
extern void txmit( uint8_t c ) ;
extern void uputs( register char *string ) ;
extern uint16_t rxuart( void ) ;
extern void txmit2nd( uint8_t c ) ;
extern uint16_t rx2nduart( void ) ;
extern void UART3_Configure( uint32_t baudrate, uint32_t masterClock) ;
extern void txmitBt( uint8_t c ) ;
extern int32_t rxBtuart( void ) ;

extern void poll2ndUsart10mS( void ) ;
//extern void charProcess( uint8_t byte ) ;
extern void poll2ndUsart10mS( void ) ;
extern void startPdcUsartReceive( void ) ;
//extern void endPdcUsartReceive( void ) ;
extern void rxPdcUsart( void (*pChProcess)(uint8_t x) ) ;
extern uint32_t txPdcUsart( uint8_t *buffer, uint32_t size, uint32_t receive ) ;
extern uint32_t txPdcPending( void ) ;
extern uint32_t txCom2Uart( uint8_t *buffer, uint32_t size ) ;

extern void per10ms( void ) ;
extern uint8_t getEvent( void ) ;
extern void pauseEvents(uint8_t event) ;
extern void killEvents(uint8_t event) ;
extern void init_spi( void ) ;
extern void end_spi( void ) ;
extern void eeprom_write_enable( void ) ;
extern uint32_t eeprom_read_status( void ) ;
extern uint32_t  eeprom_write_one( uint8_t byte ) ;
extern uint32_t spi_operation( uint8_t *tx, uint8_t *rx, uint32_t count ) ;
extern uint32_t spi_action( uint8_t *command, uint8_t *tx, uint8_t *rx, uint32_t comlen, uint32_t count ) ;
extern uint32_t spi_PDC_action( uint8_t *command, uint8_t *tx, uint8_t *rx, uint32_t comlen, uint32_t count ) ;
extern void crlf( void ) ;
extern void p8hex( uint32_t value ) ;
extern void p4hex( uint16_t value ) ;
extern void p2hex( unsigned char c ) ;
extern void hex_digit_send( unsigned char c ) ;
#ifdef PCBSKY
extern void read_adc(void ) ;
#endif
extern void xread_9_adc(void ) ;
extern void init_adc( void ) ;
void set_stick_gain( uint32_t gains ) ;
extern void init_ssc( uint16_t baudrate ) ;
extern void eeprom_write_byte_cmp (uint8_t dat, uint16_t pointer_eeprom) ;
extern void eeWriteBlockCmp(const void *i_pointer_ram, void *i_pointer_eeprom, size_t size) ;
extern void eeprom_read_block( void *i_pointer_ram, const void *i_pointer_eeprom, register uint32_t size ) ;
void start_ppm_capture( void ) ;
void end_ppm_capture( void ) ;
extern void start_2Mhz_timer( void ) ;

#ifdef PCB9XT
extern uint8_t BlChanged ;
extern void BlSetColour( uint32_t level, uint32_t colour ) ;
extern void backlightSend() ;
extern void console9xtInit( void ) ;
#endif

extern void disable_ssc( void ) ;

#define SPORT_MODE_HARDWARE		0
#define SPORT_MODE_SOFTWARE		1
#define SPORT_POLARITY_NORMAL	0
#define SPORT_POLARITY_INVERT	1

extern void x9dSPortInit( uint32_t baudRate, uint32_t mode, uint32_t invert ) ;
extern void x9dSPortTxStart( uint8_t *buffer, uint32_t count, uint32_t receive ) ;
void disable_software_com1( void ) ;

uint32_t read32_eeprom_data( uint32_t eeAddress, register uint8_t *buffer, uint32_t size, uint32_t immediate ) ;

extern void init_SDcard( void ) ;

//------------------------------------------------------------------------------
/// Detect if SD card is connected
//------------------------------------------------------------------------------
#ifdef PCBSKY
#define CardIsConnected() ( (PIOB->PIO_PDSR & PIO_PB7) == 0 )
#endif

extern uint32_t Card_ID[4] ;
extern uint32_t Card_SCR[2] ;
extern uint32_t Card_CSD[4] ;
extern uint32_t Sd_128_resp[4] ;
extern uint32_t Sd_rca ;
//extern uint32_t Cmd_55_resp ;

extern uint32_t Card_state ;

extern uint32_t SD_SetBusWidth( uint32_t busWidth) ;
extern void SD_EnableHsMode( uint8_t hsEnable) ;
extern uint32_t SD_SetSpeed( uint32_t mciSpeed ) ;
extern void SD_Reset( uint8_t keepSettings) ;
extern uint32_t sd_cmd55( void ) ;
extern uint32_t sd_acmd41( void ) ;
extern uint32_t sd_cmd2( void ) ;
extern uint32_t sd_cmd3( void ) ;
extern uint32_t sd_cmd7( void ) ;
extern uint32_t sd_cmd9( void ) ;
extern uint32_t sd_cmd17( uint32_t address, uint32_t *presult ) ;
extern uint32_t sd_acmd6( void ) ;
extern uint32_t sd_acmd51( uint32_t *presult ) ;
extern void sdPoll10mS( void ) ;
extern uint32_t sd_card_ready( void ) ;
extern uint32_t sd_read_block( uint32_t block_no, uint32_t *data ) ;

class Key
{
#define FILTERBITS      4
#define FFVAL          ((1<<FILTERBITS)-1)
#define KSTATE_OFF      0
#define KSTATE_RPTDELAY 95 // gruvin: longer dely before key repeating starts
  //#define KSTATE_SHORT   96
#define KSTATE_START   97
#define KSTATE_PAUSE   98
#define KSTATE_KILLED  99
  uint8_t m_vals:FILTERBITS;   // key debounce?  4 = 40ms
  uint8_t m_dblcnt:2;
  uint8_t m_cnt;
  uint8_t m_state;
public:
  void input(bool val, EnumKeys enuk);
  bool state()       { return m_vals==FFVAL;                }
  bool isKilled()    { return m_state == KSTATE_KILLED ;    }
  void pauseEvents() { m_state = KSTATE_PAUSE;  m_cnt   = 0;}
  void killEvents()  { m_state = KSTATE_KILLED; m_dblcnt=0; }
  uint8_t getDbl()   { return m_dblcnt;                     }
};

extern Key keys[NUM_KEYS] ;

#endif