module producer(producer_data, producer_iclk);
  input reg producer_iclk;
  output reg [3:0]producer_data;
  initial producer_data=0;
  always @(posedge producer_iclk) 
    begin
      producer_data = producer_data+1;
  end
endmodule

module consumer(consumer_iclk, consumer_data, consumer_req);
  input reg consumer_iclk;
  input reg [3:0] consumer_data;
  output reg consumer_req;
  initial consumer_req=0;
  always @(posedge consumer_iclk)
   begin
      consumer_req=~consumer_req;
     // $display("time=%t, consumer request=%d", $time, consumer_req);
    end
  
  endmodule

module fifo(producer_data, consumer_req, consumer_data);
  input reg [3:0] producer_data;
  input reg consumer_req;
  output reg [3:0] consumer_data;
  integer i;
  reg [3:0] memory[9:0];
  always@(producer_data)
    begin
     if(producer_data<=4'b1010)
       begin
       for(i=0;i<10;i++)
         begin
           memory[i]=producer_data; 
         end
         //$display("time=%t, Producer data in fifo=%d", $time, producer_data);
       end
     else
       $finish;
    end
  always@(consumer_req)
    begin
      if(consumer_req==1)
         begin
           for(i=0; i<10; i++)
               begin
                 consumer_data=memory[i];
               end
            // $display("time=%t, consumer data=%d", $time, consumer_data);
         end 
      else
        consumer_data=4'b0;
    end
  
endmodule