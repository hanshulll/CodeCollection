interface intf(input master_clk1, input slave_clk1);  
  modport master_m(input master_clk1, import task produce(int data));
  modport slave_s(input slave_clk1, export task produce(int data));
endinterface:intf 
                
module master(intf itf);
  
  reg [3:0] data_m;
  initial data_m=0;
  
  always@(posedge itf.master_clk1)
    begin
      itf.produce(data_m++);
      $display("time=%t, master data=%d", $time, data_m);
    end
  
endmodule
 
                
module slave(intf itf);
   reg [3:0] master_add;
   reg [3:0] slave_add;
   reg [3:0] data_s;
   reg [3:0] mem[9:0];
   
  event slave_e;
   initial master_add=0;
   initial slave_add=0;
  
  task itf.produce(input int data);
    if(master_add>=10) begin
      ->slave_e; end
    else
      mem[master_add++] = data;
  endtask
 
  always@(slave_e)                
   begin
     data_s=mem[slave_add++];
     $display("time=%t, slave data=%d", $time, data_s);
      if(slave_add>=10)
           $display("no data to consume");
       end                   
endmodule                 
