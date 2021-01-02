Public Class DCNS



    Dim p1me As Integer
    Dim p2me As Integer
    Dim p3me As Integer
    Dim dtme As Integer
    Dim dcr As Integer
    Dim scle As Integer
    Dim lor As Integer

    Dim dt_p1_x As Integer
    Dim dt_p1_y As Integer
    Dim dt_p1_d As Single

    Dim dt_p2_x As Integer
    Dim dt_p2_y As Integer
    Dim dt_p2_d As Single

    Dim dt_p3_x As Integer
    Dim dt_p3_y As Integer
    Dim dt_p3_d As Single

    Dim dt_x As Integer
    Dim dt_y As Integer

    Dim p1_x As Integer
    Dim p1_y As Integer

    Dim p2_x As Integer
    Dim p2_y As Integer

    Dim p3_x As Integer
    Dim p3_y As Integer

    Dim dt_p1_a As Single
    Dim dt_p2_a As Single
    Dim dt_p3_a As Single

    Dim dt_p1_div As Single
    Dim dt_p2_div As Single
    Dim dt_p3_div As Single
    Dim it_x As Integer
    Dim it_y As Integer
    Dim it_p1_a As Single
    Dim it_p1_div As Single

    Dim it_p1_d As Integer
    Dim be_it_d As Single
    Dim dt_it_d As Single
    Dim it_p1_x As Integer
    Dim it_be_x As Integer
    Dim it_dt_x As Integer
    Dim it_p1_y As Integer
    Dim it_be_y As Integer
    Dim it_dt_y As Integer



    Dim be_x As Integer
    Dim be_y As Integer
    Dim be_p1_x As Integer
    Dim be_p1_y As Integer
    Dim be_p2_x As Integer
    Dim be_p2_y As Integer
    Dim be_p3_x As Integer
    Dim be_p3_y As Integer

    Dim be_p1_a As Single
    Dim be_p2_a As Single
    Dim be_p3_a As Single

    Dim be_p1_div As Single
    Dim be_p2_div As Single
    Dim be_p3_div As Single

    Dim be_dt_d As Single
    Dim be_dt_div As Single
    Dim be_dt_a As Single
    Dim be_dt_x As Integer
    Dim be_dt_y As Integer
    Dim cd As String
    Dim px As Single
    'Variables 




    Private Sub MAIN_SOF_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        p1me = 0
        p2me = 0
        p3me = 0
        dtme = 0
        px = 0.02676
        Button5.Hide()

        Timer1.Start()
    End Sub



    Private Sub MAIN_SOF_MouseClick(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles Me.MouseClick
        If dcr = 0 Then
            DT_M.Visible = True
            DT_M.Location = New Point(e.X, e.Y)
            dt_x = e.X
            dt_y = e.Y
        ElseIf dcr = 1 Then
            P1_M.Visible = True
            P1_M.Location = New Point(e.X, e.Y)
            p1_x = e.X
            p1_y = e.Y
        ElseIf dcr = 2 Then
            P2_M.Visible = True
            P2_M.Location = New Point(e.X, e.Y)
            p2_x = e.X
            p2_y = e.Y
        ElseIf dcr = 3 Then
            P3_M.Visible = True
            P3_M.Location = New Point(e.X, e.Y)
            p3_x = e.X
            p3_y = e.Y
        End If

    End Sub

    Private Sub MAIN_SOF_MouseMove(ByVal sender As Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles Me.MouseMove
        MX.Text = e.X
        m_y.Text = e.Y
    End Sub

    Private Sub OvalShape1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OvalShape1.Click, BE.Click
        p1me = 0
        p2me = 0
        p3me = 0
        dtme = 1
        dcr = 0
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        p1me = 0
        p2me = 0
        p3me = 0
        dtme = 1
        dcr = 4
    End Sub

    Private Sub OvalShape3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OvalShape3.Click
        p1me = 0
        p2me = 1
        p3me = 0
        dtme = 0
        dcr = 2
    End Sub

    Private Sub OvalShape2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OvalShape2.Click
        p1me = 1
        p2me = 0
        p3me = 0
        dtme = 0
        dcr = 1
    End Sub

    Private Sub OvalShape4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OvalShape4.Click
        p1me = 0
        p2me = 0
        p3me = 1
        dtme = 0
        dcr = 3
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        If dt_x > p1_x Then
            dt_p1_x = dt_x - p1_x
        ElseIf dt_x < p1_x Then
            dt_p1_x = p1_x - dt_x
        End If
        If dt_y > p1_y Then
            dt_p1_y = dt_y - p1_y
        ElseIf dt_y < p1_y Then
            dt_p1_y = p1_y - dt_y
        End If
        dt_p1_d = px * ((((dt_p1_x) ^ 2) + ((dt_p1_y) ^ 2)) ^ (1 / 2))

        If dt_x > p2_x Then
            dt_p2_x = dt_x - p2_x
        ElseIf dt_x < p2_x Then
            dt_p2_x = p2_x - dt_x
        End If
        If dt_y > p2_y Then
            dt_p2_y = dt_y - p2_y
        ElseIf dt_y < p2_y Then
            dt_p2_y = p2_y - dt_y
        End If
        dt_p2_d = px * ((((dt_p2_x) ^ 2) + ((dt_p2_y) ^ 2)) ^ (1 / 2))


        If dt_x > p3_x Then
            dt_p3_x = dt_x - p3_x
        ElseIf dt_x < p3_x Then
            dt_p3_x = p3_x - dt_x
        End If
        If dt_y > p3_y Then
            dt_p3_y = dt_y - p3_y
        ElseIf dt_y < p3_y Then
            dt_p3_y = p3_y - dt_y
        End If
        dt_p3_d = px * ((((dt_p3_x) ^ 2) + ((dt_p3_y) ^ 2)) ^ (1 / 2))
        TextBox1.Text = dt_p1_d
        TextBox2.Text = dt_p2_d
        TextBox3.Text = dt_p3_d
        '-------------------------------------------------------------------------------------
        dt_p1_div = dt_p1_y / dt_p1_x
        dt_p1_a = (Math.Atan(dt_p1_div) * 180) / Math.PI
        dt_p2_div = dt_p2_y / dt_p2_x
        dt_p2_a = (Math.Atan(dt_p2_div) * 180) / Math.PI
        dt_p3_div = dt_p3_y / dt_p3_x
        dt_p3_a = (Math.Atan(dt_p3_div) * 180) / Math.PI
        TextBox6.Text = dt_p1_a
        TextBox5.Text = dt_p2_a
        TextBox4.Text = dt_p3_a
        '-------------------------------------------------------------------------------------
        be_x = BE.Location.X
        be_y = BE.Location.Y
        be_p1_y = be_y - p1_y
        If be_x > p1_x Then
            be_p1_x = be_x - p1_x
        Else
            be_p1_x = p1_x - be_x
        End If
        be_p1_div = be_p1_y / be_p1_x
        be_p1_a = (Math.Atan(be_p1_div) * 180) / Math.PI

        be_p2_y = be_y - p2_y
        If be_x > p2_x Then
            be_p2_x = be_x - p2_x
        Else
            be_p2_x = p2_x - be_x
        End If
        be_p2_div = be_p2_y / be_p2_x
        be_p2_a = (Math.Atan(be_p2_div) * 180) / Math.PI

        be_p3_y = be_y - p3_y
        If be_x > p3_x Then
            be_p3_x = be_x - p3_x
        Else
            be_p3_x = p3_x - be_x
        End If
        be_p3_div = be_p3_y / be_p3_x
        be_p3_a = (Math.Atan(be_p3_div) * 180) / Math.PI

        TextBox9.Text = be_p1_a
        TextBox8.Text = be_p2_a
        TextBox7.Text = be_p3_a

        '-------------------------------------------------------------------------------
        If be_x > dt_x Then
            be_dt_x = be_x - dt_x
        Else
            be_dt_x = dt_x - be_x
        End If
        be_dt_y = be_y - dt_y
        be_dt_d = px * ((((be_dt_x) ^ 2) + ((be_dt_y) ^ 2)) ^ (1 / 2))
        be_dt_div = be_dt_y / be_dt_x
        be_dt_a = (Math.Atan(be_dt_div) * 180) / Math.PI

        If be_x > dt_x Then
            lor = 2 ' left
        Else : lor = 1 ' right

        End If
        it_x = be_x
        it_y = dt_y

        If it_x > p1_x Then
            it_p1_x = it_x - p1_x
        Else
            it_p1_x = p1_x - it_x
        End If
        If it_y > p1_y Then
            it_p1_y = it_y - p1_y
        Else
            it_p1_y = p1_y - it_y
        End If
        it_p1_d = px * ((((it_p1_x) ^ 2) + ((it_p1_y) ^ 2)) ^ (1 / 2))

        be_it_d = px * (be_y - it_y)
        If it_x > dt_x Then
            dt_it_d = px * (it_x - dt_x)
        Else : dt_it_d = px * (dt_x - it_x)
        End If
        it_p1_div = it_p1_y / it_p1_x
        it_p1_a = (Math.Atan(it_p1_div) * 180) / Math.PI

    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        BE.Location = New Point(Me.Size.Width / 2, 707)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        If RadioButton1.Checked = True Then
            scle = 1
        ElseIf RadioButton2.Checked = True Then
            scle = 2
        ElseIf RadioButton3.Checked = True Then
            scle = 3
        ElseIf RadioButton4.Checked = True Then
            scle = 4
        End If

        ' cd = dt_p1_d & ":" & dt_p1_a & ":" & be_p1_a & ":" & it_p1_d & ":" & it_p1_a & ":" & be_it_d & ":" & dt_it_d & ":" & lor & "|" 
        TextBox10.Text = lor & ":" & be_dt_d & ":" & be_dt_a & ":" & dt_p1_d & ":" & dt_p2_d & ":" & dt_p3_d & ":" & dt_p1_a & ":" & dt_p2_a & ":" & dt_p3_a & ":" & be_p1_a & ":" & be_p2_a & ":" & be_p3_a & ":" & scle & "|"
        Button5.Show()
        Upload.RichTextBox1.Text = Me.TextBox10.Text
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        Form4.Show()
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        Form2.Show()
    End Sub



End Class

