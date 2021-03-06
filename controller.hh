#ifndef CONTROLLER_HH
#define CONTROLLER_HH

#include <stdint.h>

/* Flow controller interface */

class Controller
{
private:
  bool debug_; /* Enables debugging output */

  /* Add member variables here */
  unsigned int window;
  float window_float;
  unsigned int timeout;
  unsigned int rtt;
  unsigned int srtt;
  float alpha;
  int dev;
  int rttdev;
  float beta;
  
  //holds recent rtts
  unsigned int rtt_rec [3];
  
  //number of recent rtts that are stored
  int rsize;
  
  //Average of recent rtts
  unsigned int avg;
  
  float ratio;
  int wb;

public:
  /* Public interface for the flow controller */
  /* You can change these if you prefer, but will need to change
     the call site as well (in datagrump-sender.cc) */

  /* Default constructor */
  Controller( const bool debug );

  /* Get current window size, in packets */
  unsigned int window_size( void );

  /* A packet was sent */
  void packet_was_sent( const uint64_t sequence_number,
			const uint64_t send_timestamp );

  /* An ack was received */
  void ack_received( const uint64_t sequence_number_acked,
		     const uint64_t send_timestamp_acked,
		     const uint64_t recv_timestamp_acked,
		     const uint64_t timestamp_ack_received );
		     
  void timout_detected();
  void debugging(int n);
  
  
  /* How long to wait if there are no acks before sending one more packet */
  unsigned int timeout_ms( void );
};

#endif
