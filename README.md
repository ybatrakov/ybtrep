# Yet another Bridge for Thomson Reuters Enterprise Platform

YBTREP is OpenMAMA middleware bridge for TREP (Thomson Reuters Enterprise Platform). Its goal is to implement high-performance transport for applications using OpenMAMA library for consuming and publishing market data to TREP infrastructure.

## Design
This bridge works in "sequential mode". Every time you call mama_dispatch(timeout) on a queue, all associated transports do their job (reading events from network, send heartbeats back to ADS, etc). Upon return from mama_dispatch, the bridge stays idle untill next call to mama_dispatch. This allows to get rid of deadlocks, data races and other concurrency issues. This also saves CPU cycles otherwise spent on synchronization.